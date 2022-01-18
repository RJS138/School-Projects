package Model;


public class Person {

    //Attributes
    private String name;
    private int weight;
    private String hometown;
    private String highSchool;
    private Height height;

    //Initializing Constructor
    public Person(String inf_name, int inf_weight, String inf_hometown, String inf_highSchool, Height inf_height) {
        name = inf_name;
        weight = inf_weight;
        hometown = inf_hometown;
        highSchool = inf_highSchool;
        height = inf_height;
    }

    //Default Constructor
    public Person() {
        this("", 0, "N/A", "N/A", new Height ());
    }

    //toString() Method
    public String toString() {
        return "Person{Name=" + name + ", Height= " + getHeight() + ", Weight=" + weight + ", Hometown=" + hometown + ", HighSchool=" + highSchool + "}";
    }

    /**
     * @return the name
     *
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return the weight
     */
    public int getWeight() {
        return weight;
    }

    /**
     * @param weight the weight to set
     */
    public void setWeight(int weight) {
        this.weight = weight;
    }

    /**
     * @return the hometown
     */
    public String getHometown() {
        return hometown;
    }

    /**
     * @param hometown the hometown to set
     */
    public void setHometown(String hometown) {
        this.hometown = hometown;
    }

    /**
     * @return the highSchool
     */
    public String getHighSchool() {
        return highSchool;
    }

    /**
     * @param highSchool the highSchool to set
     */
    public void setHighSchool(String highSchool) {
        this.highSchool = highSchool;
    }

    /**
     * @return the height
     */
    public Height getHeight() {
        return height;
    }

    /**
     * @param height the height to set
     */
    public void setHeight(Height height) {
        this.height = height;
    }
}

