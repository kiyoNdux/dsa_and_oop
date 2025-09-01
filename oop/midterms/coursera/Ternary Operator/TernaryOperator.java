class TernaryOperator {
    public static void main(String[] args) {
        int x = 10;
        int y;

        // Using the ternary operator to assign a value to y based on the condition
        y = (x > 7) ? 2 : 5;
        System.out.println("The value of y is: " + y);

        x = 7; 
        y = (x > 7) ? 2 : 5;
        System.out.println("The value of y is: " + y);
    }
}