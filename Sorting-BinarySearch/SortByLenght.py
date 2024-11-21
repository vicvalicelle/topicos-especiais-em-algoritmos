# beecrowd 1244 - Sort By Lenght

# Number of test cases (N)
num_cases = int(input())  # Read the number of test cases

# List to hold the input strings
strings = []

# Read each string for the test cases
for _ in range(num_cases):
    string = input()  # Read a string from input
    strings.append(string)  # Add the string to the list

# Function to sort the words by length
def sort_by_length(string):
    words = string.split()  # Split the string into words based on spaces
    # Sort the words by length (ascending order), maintaining original order if lengths are the same
    return sorted(words, key=len)

# Process each string
for string in strings:
    sorted_words = sort_by_length(string)  # Get the sorted words for the string
    print(" ".join(sorted_words))  # Print the words joined by spaces
