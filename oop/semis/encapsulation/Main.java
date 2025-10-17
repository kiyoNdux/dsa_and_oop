class Person {
	private String name;

	public String getName() {
		return name;
	}

	public void setName(String newName) {
		this.name = newName;
	}
}

// public class Main {
//	public static void main(String[] args) {
//		Person myObj = new Person();
// 		myObj.name = "John";  // error
//    		System.out.println(myObj.name); // error 
//  	}
// }

public class Main {
  	public static void main(String[] args) {
    		Person myObj = new Person();
    		myObj.setName("John"); // Set the value of the name variable to "John"
    		System.out.println(myObj.getName());
  	}
}