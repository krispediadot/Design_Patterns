/*
  Output:
  Singleton Instance: 1159190947
  Singleton Instance: 1159190947
*/

public class App {
    public static void main(String[] args) throws Exception {
        Singleton pSingleton = Singleton.getInstance();
        Singleton cSingleton = Singleton.getInstance();

        System.out.println("Singleton Instance: " + pSingleton.hashCode());
        System.out.println("Singleton Instance: " + cSingleton.hashCode());
    }
}
