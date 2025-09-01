class DayOfWeek{
    public static void main(String[] args) {
        int day = 3; // Let's say 1 = Monday, 2 = Tuesday, ..., 7 = Sunday
        String dayName;

        switch (day) {
            case 1:
                dayName = "Monday";
                break;
            case 2:
                dayName = "Tuesday";
                break;
            case 3:
                dayName = "Wednesday";
                break;
            case 4:
                dayName = "Thursday";
                break;
            case 5:
                dayName = "Friday";
                break;
            case 6:
                dayName = "Saturday";
                break;
            case 7:
                dayName = "Sunday";
                break;
            default:
                dayName = "Invalid day"; // Handle invalid input
                break;
        }

        System.out.println("The day is: " + dayName);
    }
}