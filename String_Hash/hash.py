
class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def insert(self, cadena):
        hash_value = simple_hash(cadena)
        index = hash_value % self.size #si la tabla es de tamaño 10, y el texto suma 20, 20 % 10 = 2, entonces estara en indice 2
        self.table[index].append(cadena)
        

def simple_hash(cadena):
    hash_value = 0
    for character in cadena:
        hash_value += ord(character)
    return hash_value
