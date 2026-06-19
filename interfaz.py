import tkinter as tk #Crea una ventana para lograr ver la interfaz
import serial #establece la comunicacion via bluetooth con el arduino 
import time #permite dividir intervalos de tiempo

bluetooth = serial.Serial('COM13', 9600, timeout=1) #define bluetooth como una conexion serial que aparece en el puerto COM14, la velocidad de transmicion y el tiempo de espera de respuesta
time.sleep(2) # pone un tiempo de 2 segundos de espera para la respuesta
def enviar_comando(cmd): #define la funcion de enviar comandos con letras especificas
    bluetooth.write((cmd).encode())   # Envía el comando
    time.sleep(0.3)
    print("Arduino:",cmd) 

def caminar():
    enviar_comando('C') #activa la funcion caminar con la letra c
    
def levantarse():
    enviar_comando('L')#activa la funcion levantarse con la letra L

def pararse():
    enviar_comando('P') #activa la funcion pararse con la letra p
    
    
def atacar():
    enviar_comando('A') #activa la funcion atacar con la letra a 
    
    
def sonido():
    enviar_comando('R') #activa el sonido con rc
    
ventana = tk.Tk()
ventana.title("Robot Cuadrúpedo")
ventana.geometry("300x250") #define las dimensiones de la ventana principal 

tk.Button(ventana, text="CAMINAR", command=caminar,
          width=20, height=2).pack(pady=10)

tk.Button(ventana, text="PARARSE", command=pararse,
          width=20, height=2).pack(pady=10)

tk.Button(ventana, text="LEVARTARSE", command=levantarse,
          width=20, height=2).pack(pady=10)

tk.Button(ventana, text="ATACAR", command=atacar,
          width=20, height=2).pack(pady=10)
tk.Button(ventana, text="REPRODUCIR MUSICA", command=sonido,
          width=20, height=2).pack(pady=10) #crea botones para todas las funciones en la ventana principal
ventana.mainloop()
