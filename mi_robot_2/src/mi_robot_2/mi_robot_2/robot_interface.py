import tkinter as tk
from tkinter import filedialog
from tkinter import messagebox
from tkinter import Canvas
from PIL import Image, ImageTk, ImageGrab
import pyautogui
from pynput import keyboard

root = tk.Tk()
root.geometry('750x600')
root.title('robot_teleop')
root.configure(bg='#ff3333')
img = Image.open("cuadricula.png")
imagen = img.resize((400,400))
new_image = ImageTk.PhotoImage(imagen)
etiqueta_imagen = tk.Label(root,image=new_image)

ancho = 750
alto = 600
pos_x = 400
pos_y = 300

canvas = Canvas(root, width = ancho, height = alto)
canvas.configure(bg = '#ff3333')
canvas.pack()
canvas.create_image(pos_x,pos_y,image=new_image)

av = 3
x1 = pos_x
y1 = pos_y
x2 = pos_x +5
y2 = pos_y +5

text_frame_grafica = tk.Text(root, height=1, width=25,font=("Futura", 20))
text_frame_grafica.place(x=350,y=30)

label_grafica = tk.Label(root, text="Introduce el nombre:",bg='#ff3333',font=("Futura", 20))
label_grafica.place(x=0,y=32)

def open_file():
    file_path = filedialog.askopenfilename(initialdir = "/", title = "Select file", filetypes = (("PNG files", "*.png"), ("JPEG files", "*.jpg"), ("All Files", "*.*")))
    try:
        global image
        image = Image.open(file_path)
        image = image.resize((400,400))
        render = ImageTk.PhotoImage(image)
        img = tk.Label(root, image=render)
        img.image = render
        # img.place(x=100,y=150)
        canvas.create_image(pos_x,pos_y,image=render)
    except:
        messagebox.showerror("Error", "Failed to open the image.")

open_file_button = tk.Button(root, text="Seleccionar Imagen", command=open_file, height=2, width=20, font=("Futura", 12))
open_file_button.place(x=30,y=520)

def save_screenshot():
    x = root.winfo_rootx()
    y = root.winfo_rooty()
    width = root.winfo_width()
    height = root.winfo_height()
    # # Crea una imagen a partir de la ventana actual
    # image = ImageGrab.grab((x, y, x + width, y + height))


    dx = (width-750)/2
    # Crea una imagen a partir de la ventana actual
    image = ImageGrab.grab((x+dx+200, y+100, x+dx+600, y + 500))

    # Guarda la imagen en un archivo
    texto = str(text_frame_grafica.get("1.0",'end-1c'))
    file_path = filedialog.asksaveasfilename(defaultextension=".png", initialfile= texto + ".png", filetypes=(("PNG files", "*.png"), ("JPEG files", "*.jpg"), ("All Files", "*.*")))
    image.save(file_path)

# Crea el botón
save_screenshot_button = tk.Button(root, text="Tomar pantalla", command=save_screenshot, height=1, width=15, font=("Futura", 12))
save_screenshot_button.place(x=30,y=450)

def on_press(key):
    try:
        global x1, y1, x2, y2
        if key.char == "w":
            y1 += -av
            y2 += -av
            canvas.create_rectangle(x1, y1, x2, y2, fill='blue', outline='blue')         
        if key.char == "s":
            y1 += av
            y2 += av
            canvas.create_rectangle(x1, y1, x2, y2, fill='blue', outline='blue')
        if key.char == "a":
            x1 += -av
            x2 += -av
            canvas.create_rectangle(x1, y1, x2, y2, fill='blue', outline='blue')
        if key.char == "d":
            x1 += av
            x2 += av
            canvas.create_rectangle(x1, y1, x2, y2, fill='blue', outline='blue')
        print('{0} presionada'.format(
                key.char))
    except AttributeError:
        print('{0} presionada'.format(
            key))

def on_release(key):
    print('{0}'.format(
        key))
    if key == keyboard.Key.esc:
        # Stop listener
        return False

listener = keyboard.Listener(
    on_press=on_press,
    on_release=on_release)
listener.start()

# Run the main loop
root.mainloop()
listener.join()

'''
# Create a new tkinter window
#ESTO DESPUES TOCA AÑADIRLO A UNA FUNCION
root = tk.Tk()
root.geometry('850x600')
root.configure(bg='#ff3333')

# Set the title of the window
root.title("robot_interface")

# Create a label widget
label = tk.Label(root, text="Hello, World!")
label.pack()

# Create a button widget
button = tk.Button(root, text="Click me!")
button.pack()

# Run the main loop
root.mainloop()


'''

    

