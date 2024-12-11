# Function to sort the array using Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Function to sort the array using Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Function to display the top five scores
def display_top_five(arr):
    top_five = arr[-1:-6:-1]  # Get the last five elements in descending order
    print("Top five scores:", top_five)

# Main function
def main():
    # Example array of student percentages
    percentages = [85.6, 90.3, 78.4, 92.5, 88.9, 74.2, 95.7, 80.1, 67.4, 89.6]
    print("Original percentages:", percentages)

    # Sorting using Selection Sort
    selection_sorted = percentages[:]
    selection_sort(selection_sorted)
    print("\nSorted percentages (Selection Sort):", selection_sorted)
    display_top_five(selection_sorted)

    # Sorting using Bubble Sort
    bubble_sorted = percentages[:]
    bubble_sort(bubble_sorted)
    print("\nSorted percentages (Bubble Sort):", bubble_sorted)
    display_top_five(bubble_sorted)

main()
