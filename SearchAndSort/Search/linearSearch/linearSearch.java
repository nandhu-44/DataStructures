import java.util.Scanner;

class linearSearch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n-----Iterative(int)-----");
        int element;
        int[] array = { 1, 5, 6, 2, 5, 22, 5, 3, 5, 6, 3, 6, 3, 5, 7, 100, 4, 5, 6 };
        System.out.print("Enter element to search : ");
        element = scanner.nextInt();
        scanner.nextLine();
        int index = linearSearchFunction(array, element);
        if (index != -1) {
            System.out.println("Element found at index : " + index);
        } else {
            System.out.println("Element not found!");
        }

        System.out.println("\n-----Recursive(Object-String)-----");
        String[] stringArray = { "apple", "banana", "orange", "grape", "kiwi" };
        System.out.print("Enter fruit to search: ");
        String targetString = scanner.nextLine();
        index = linearSearchRecursive(stringArray, targetString);
        if (index != -1) {
            System.out.println("Fruit found at index: " + index);
        } else {
            System.out.println("Fruit not found!");
        }

        scanner.close();
    }

    // Implementing Iteratively.
    public static int linearSearchFunction(int[] arr, int elem) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == elem) {
                return i;
            }
        }
        return -1;
    }

    // Implementing recursively.
    public static int linearSearchRecursive(Object[] obj, Object element) {
        return linearSearchRecursive(obj, element, 0);
    }

    private static int linearSearchRecursive(Object[] obj, Object element, int n) {
        if (n >= obj.length) {
            return -1;
        } else if (element.equals(obj[n])) {
            return n;
        } else {
            return linearSearchRecursive(obj, element, n + 1);
        }

    }

}
