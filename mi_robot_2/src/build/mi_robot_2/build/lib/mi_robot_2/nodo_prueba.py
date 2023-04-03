import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class RobotCmdVelSubscriber(Node):

    def __init__(self):
        super().__init__('robot_cmd_vel_subscriber')
        self.subscription = self.create_subscription(
            Twist,
            '/robot_cmdVel',
            self.listener_callback,
            10
        )

    def listener_callback(self, msg):
        self.get_logger().info(f"Received cmdVel: linear_x={msg.linear.x}, angular_z={msg.angular.z}")

def main(args=None):
    rclpy.init(args=args)
    robot_cmd_vel_subscriber = RobotCmdVelSubscriber()
    rclpy.spin(robot_cmd_vel_subscriber)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
