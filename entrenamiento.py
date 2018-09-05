np=int(input(" usuarios a evaluar: "))
lm=1
sumed=0
while lm<=np :
    genero=input(" cual es tu genero: ")
    edad=int(input("escriba su edad: "))
    lm = lm + 1 
    sumed=sumed+edad
    promedio=sumed/np
print("el promedioes: ",promedio)
