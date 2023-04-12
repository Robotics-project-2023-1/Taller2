import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import String #Tipo de mensaje recibido en el topico robot_bot_teclas
import serial
import time
ser = serial.Serial("/dev/ttyACM0", baudrate=115200) #Modificar el puerto serie de ser necesario
ser.flush()
#dar permiso al puerto sudo chmod 666 /dev/ttyUSB0
from threading import Thread  #Crear threads para correr dos cosas simultaneamenteaaaaa
from time import sleep
global lista_a
lista_a = [0,0]
global read_serial
read_serial = ""
global posiciones
posiciones = [0.0, 0.0]

def calcular_pos(angulos):
    matriz = [0, 0, 0, 0]
    posiciones = angulos
    return posiciones


class RobotCmdVelSubscriber(Node):

    def __init__(self):
        super().__init__('nodo_prueba')
        self.subscription = self.create_subscription( Twist,'robot_teclas', self.listener_callback,10)
        self.publisher_ = self.create_publisher( Twist,'angulos', 10)
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)


    def listener_callback(self, msg):
        #mensaje = repr(self.get_logger().info(f"Received cmdVel: linear_x={msg.linear.x}, angular_z={msg.angular.z}"))aaawwwwsswsssswwwwwwwaaaaqaa
        global lista_a
        global read_serial
        global x
        global y
        lineal = int(msg.linear.x)
        angular = int(msg.angular.z)
        lista_n = [lineal, angular]
        #print(lista_n)
        entrada = ser.readline().decode('utf-8').rstrip()
        #print("ya entrada")
        ser.flush() 
        if entrada:
            angulos = entrada.split(',')
            print(angulos)
        
        if(lista_n != lista_a):
            #print(lista_n)
            #print(lista_a)
            #print(f"{lineal},{angular}\n")
            ser.write(f"{lineal},{angular}\n".encode())
            #print(read_serial)
            time.sleep(0.1)
        lista_a = lista_n

    def timer_callback(self):
        global posiciones
        msg_angulos = Twist()
        msg_angulos.linear.x = posiciones[0]
        msg_angulos.linear.y = posiciones[1]
        self.publisher_.publish(msg_angulos)







def main(args=None):
    rclpy.init(args=args)
    #t = Thread(target=leer_encoders) #inicia un segundo hilo en el cual va a correr la interfaz
    #t.start() #inicia la interfaz
    robot_cmd_vel_subscriber = RobotCmdVelSubscriber()
    rclpy.spin(robot_cmd_vel_subscriber)
    #t.join()
    rclpy.shutdown()

if __name__ == '__main__':
    main()