import hashlib

# Get filename and n from user
filename = input("Enter the name of your file: ")
#filename = filename + ".txt"
n = int(input("Enter a value for n: "))

def hash_file(file_content, n):
    if n % 4 != 0 or not (16 <= n <= 64):
        raise ValueError("n must be a multiple of 4 and between 16 and 64")

    # Create the hash using SHA256
    hash_obj = hashlib.sha256(file_content.encode('utf-8'))
    full_hash = hash_obj.hexdigest()

    # Convert the hash to binary
    binary_hash = bin(int(full_hash, 16))[2:].zfill(256)

    # Truncate the hash to n bits
    truncated_hash = binary_hash[:n]

    print(f"Truncated hash to {n} bits: {truncated_hash}")
    return truncated_hash

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def insert(self, hash_value, value):
        index = hash_value % self.size
        self.table[index].append(value)

    def display(self):
        for i in range(self.size):
            print(f"Index {i}: {self.table[i]}")

def open_file(filename, n):
    try:
        # Open the file with proper encoding for cross-platform compatibility
        with open(filename, 'r', encoding='utf-8') as file:
            hash_table = HashTable(n)
            for line in file:
                # Split the line into words using whitespace as separators
                for word in line.strip().split():
                    word_hash = hash_file(word, n)
                    hash_table.insert(word_hash, word)
            return hash_table
    except FileNotFoundError:
        print(f"Error: The file '{filename}' was not found")
    except Exception as e:
        print(f"Error: An error occurred while reading the file: '{e}'")

hash_table = open_file(filename, n)
if hash_table:
    hash_table.display()
else:
    print("Error opening or processing the file.")