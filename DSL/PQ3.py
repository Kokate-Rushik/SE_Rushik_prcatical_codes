def remove_duplicates(books):
    unique_books = []
    for book in books:
        if book not in unique_books:
            unique_books.append(book)
    return unique_books

def sort_books_by_cost(books):

    n = len(books)
    sorted_books = books[:]
    for i in range(n):
        for j in range(0, n-i-1):
            if sorted_books[j][1] > sorted_books[j+1][1]:
                sorted_books[j], sorted_books[j+1] = sorted_books[j+1], sorted_books[j]
    return sorted_books

def count_books_above_cost(books, threshold=500):
    count = 0
    for _, cost in books:
        if cost > threshold:
            count += 1
    return count

def filter_books_below_cost(books, threshold=500):
    filtered_books = []
    for book in books:
        if book[1] < threshold:
            filtered_books.append(book)
    return filtered_books

def main():
    books = [
        ("Book A", 450),
        ("Book B", 600),
        ("Book C", 300),
        ("Book D", 450),
        ("Book E", 750),
        ("Book A", 450),
        ("Book F", 200),
    ]
    
    books_no_duplicates = remove_duplicates(books)
    sorted_books = sort_books_by_cost(books_no_duplicates)
    count_above_500 = count_books_above_cost(books_no_duplicates)
    books_below_500 = filter_books_below_cost(books_no_duplicates)
    
    print("Books with duplicates removed:")
    for book in books_no_duplicates:
        print(book)
    
    print("\nBooks sorted by cost:")
    for book in sorted_books:
        print(book)
    
    print(f"\nNumber of books with cost more than 500: {count_above_500}")
    
    print("\nBooks with cost less than 500:")
    for book in books_below_500:
        print(book)

if __name__ == "__main__":
    main()
