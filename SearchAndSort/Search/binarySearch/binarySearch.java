import java.util.Arrays;

public class binarySearch {
        public static void main(String[] args) {
        Integer[] array = { 1, 5, 9, 13, 25, 30, 35, 40, 42, 50 };
        Integer targetElement = 50;
        Arrays.sort(array);
        int index = binarySearchRecursive(array, targetElement);
        if (index != -1) {
            System.out.println("Element found at index : " + index);
        } else {
            System.out.println("Element not found! ");
        }
    }

    public static int binarySearchRecursive(Integer[] obj, Comparable<Integer> element) {
        return binarySearchRecursive(obj, element, 0, obj.length - 1);
    }

    private static int binarySearchRecursive(Integer[] obj, Comparable<Integer> element, int low, int high) {
        if (low > high) {
            return -1;
        }
        int mid = (low + high) / 2;
        int comp = element.compareTo(obj[mid]);
        if (comp == 0) {
            return mid;
        } else if (comp > 0) {
            return binarySearchRecursive(obj, element, mid + 1, high);
        } else {
            return binarySearchRecursive(obj, element, low, mid - 1);
        }
    }
}

// public class binarySearch<T extends Comparable<T>> {
//     public static void main(String[] args) {
//         Integer[] array = { 1, 5, 9, 13, 25, 30, 35, 40, 42, 50 };
//         Integer targetElement = 30;

//         binarySearch<Integer> binarySearch = new binarySearch<>();
//         int index = binarySearch.binarySearchRecursive(array, targetElement);
//         if (index != -1) {
//             System.out.println("Element found at index : " + index);
//         } else {
//             System.out.println("Element not found! ");
//         }
//     }

//     public int binarySearchRecursive(T[] array, T target) {
//         return binarySearchRecursive(array, target, 0, array.length - 1);
//     }

//     private int binarySearchRecursive(T[] array, T target, int low, int high) {
//         if (low > high) {
//             return -1;
//         }
//         int mid = (low + high) / 2;
//         int comp = target.compareTo(array[mid]);
//         if (comp == 0) {
//             return mid;
//         } else if (comp < 0) {
//             return binarySearchRecursive(array, target, low, mid - 1);
//         } else {
//             return binarySearchRecursive(array, target, mid + 1, high);
//         }
//     }
// }
