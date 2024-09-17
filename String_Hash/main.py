import hashlib

def hash_file(file_content, n):
    if n % 4 != 0 or not (16 <= n <= 64):
        raise ValueError("n debe ser múltiplo de 4 y estar entre 16 y 64")

    hash_obj = hashlib.sha256(file_content.encode('utf-8'))
    full_hash = hash_obj.hexdigest()

    binary_hash = bin(int(full_hash, 16))[2:].zfill(256)
    truncated_hash = binary_hash[:n]

    print(f"Hash truncado a {n} bits: {truncated_hash}")
    return truncated_hash


def open_file(filename, n):
    try:
        with open(filename, 'r', encoding='utf-8') as file:
            for line in file:
                for word in line.strip().split():
                    yield word
    except FileNotFoundError:
        print(f"Error: El archivo '{filename}' no fue encontrado")
    except Exception as e:
        print(f"Error: Ocurrió un error al leer el archivo: '{e}'")


class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def insert(self, cadena):
        hash_value = simple_hash(cadena)
        index = hash_value % self.size
        self.table[index].append(cadena)

    def display(self):
        for i in range(self.size):
            print(f"Índice {i}: {self.table[i]}")


def simple_hash(cadena):
    hash_value = 0
    for character in cadena:
        hash_value += ord(character)
    return hash_value


filename = input("Cómo se llama tu archivo\n")
filename = filename + ".txt"
n = int(input("Ingresa una N\n"))

tabla_hash = HashTable(n)

for word in open_file(filename, n):
    word_hash = hash_file(word, n)
    tabla_hash.insert(word)

tabla_hash.display()
