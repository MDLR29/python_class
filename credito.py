opc = 0 
i = 1
total_credito = 0
print("***********************************************") 
print(".:: SELECCIONA EL PRODUCTO DE TU INTERES ::.") 
print("***********************************************") 
print("1. Credito de libranza") 
print("2. Credito de vivienda preaprobado")
print("3. Credito compra de cartera")
print("4. Credito compra de cartera de libranza")
print("5. credito de libre inversion")
opc = int(input(".:: Seleccione su opcion: "))
while opc < 1 or opc > 5 : 
    opc = int(input(".:: Error: Opcion incorrecta.  Seleccione su opcion: "))

if opc == 1:
    porc_interes =1.2;
elif opc == 2: 
    porc_interes = 1.3
elif opc == 3: 
    porc_interes = 1.4;
elif opc == 4: 
    porc_interes = 1.7;
else : 
    porc_interes = 2
    print("\n.:: INGRESO DE DATOS GENERALES ::. ")
valor = int(input("Monto del prestamo a solicitar ($): "))
cuotas = int(input("Ingrese plazo en meses de las cuotas (1-60): "))
while cuotas < 1 or cuotas > 60 :
        cuotas = int(input(".:: Error: Valor incorrecto.  Ingrese el plazo en meses de las cuotas (1-60): "))
year = int(input("Ano de nacimiento (1918-2000): "))
while year < 1918 or year > 2000 : 
    year = int(input(".:: Error: Ano de nacimiento no valido.  Ingrese el ano de nacimiento (1918-2000): "))

cuota_sin_int = round(valor / cuotas,2) 
interes = round((valor * porc_interes)/100,2) 
cuota_a_pagar = cuota_sin_int + interes
age = 2018 - year
if age >= 18 and age <=24 : 
    probabilidad = "Alta" 
elif age >= 25 and age <=55 : 
    probabilidad = "Media" 
else : 

    probabilidad = "Baja"
print ("| TABLA DE AMORTIZACION")
print ("______________________________________________________________________" )
print ("|Nro. cuota | Vr. cuota sin interes | Interes      | Cuota a pagar   |" )
print ("______________________________________________________________________") 
while i <= cuotas :
    print ("|",i,"         ",cuota_sin_int,"   ",interes,"       ",cuota_a_pagar)
    total_credito = round(total_credito + cuota_a_pagar,2) 
    i = i + 1
    print ("______________________________________________________________________")
print ("| Edad: ", age) 
print ("| Tasa de interes: ", porc_interes) 
print ("| Total credito ($): ", total_credito) 
print ("| Probabilidad de prestamo: ", probabilidad)
print ("| Monto solicitado ($): ", valor) 
print ("| Total intereses ($): ", interes * cuotas)

