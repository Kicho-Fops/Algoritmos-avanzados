
def mergeSort(lista):
    
    # Caso base
    if len(lista) <= 1:
        return lista

    # neesitamos calcular los sub conjuntos a partir de la mitad de la lista
    
    mitad = len(lista) // 2 # Con division entera obtenemos el elemento del medio del array
    
    izquierda = lista[0:mitad] 
    derecha = lista[mitad:len(lista)]
    
    # Empezamos a sortear cada mitad
    # Para sortear cada mitad, necesitamos romper todos los elementos en individuales 
    # Hacemos el llamado recursivo 
    
    sortIzquierda = mergeSort(izquierda)
    sortDerecha = mergeSort(derecha)
    
    # Y los mergeamos
    
    return combinar(sortIzquierda, sortDerecha)

"""

Iba a utilizar este metodo, pero por alguina razon solo devuelve el primer elemento del array sorteado asique me fui por el de https://www.w3schools.com/dsa/dsa_algo_mergesort.php

(igual me di cuenta que la parte inicial es muy similar pero asi fue como yo le entendi)



def combinar(izq, der):
    total = []
    for elemento in izq:
        for otroelemento in der:
            if elemento <= otroelemento:
                total.append(elemento)
                break
            else:
                total.append(otroelemento)
    return total    
    

"""


def combinar(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])

    return result



lista_sortear = [5,2,3,4,8,9,11,3,11,5,6,66]

input("Presione enter para continuar")
print("La lista sorteada es: ", mergeSort(lista_sortear))