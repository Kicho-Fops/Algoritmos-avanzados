def min_pesos(v, denominations):
    # Ordenar las denominaciones de mayor a menor
    denominations.sort(reverse=True)
    # Contador para el número total de monedas/billetes
    count = 0
    # Lista para guardar las monedas/billetes utilizados
    pesos_usados = []
    for pesos in denominations:
        if v >= pesos:
            num_pesos = v // pesos # Número de monedas/billetes de esta denominación
            count += num_pesos
            v -= num_pesos * pesos
            pesos_usados.append((pesos, num_pesos))
    return count, pesos_usados


denominaciones = [1000, 500, 100, 50, 20, 10, 5, 2, 1]

v = 2893

"""
cambio[2893] | [[1000,2],[500,1],...]


    2893 : [[1000,2],[500,1],...]

    [3] = len([3]) = 1


"""




total_pesos, pesos_usados = min_pesos(v, denominaciones)

print(f"Número mínimo de monedas/billetes necesarios: {total_pesos}")
print("Monedas/Billetes usados:")
for pesos, count in pesos_usados: print(f"{count} x {pesos} Rs")


cambio = {}

# print(len(cambio))

# Initialize the key with an empty list if it does not exist
if 100 not in cambio:
    cambio[100] = []

# Now you can safely append to the list


cambio[100].append([2,3])
cambio[100].append(3)

if 150 not in cambio:
    cambio[150] = []
    
cambio[150].append(4)
cambio[150].append(5)

print(cambio[100], cambio[150])  # Output should be [2]
