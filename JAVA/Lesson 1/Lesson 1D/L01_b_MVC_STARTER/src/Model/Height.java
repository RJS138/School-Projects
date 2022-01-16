
package Model;

public class Height 
{
    private int feet;
    private int inches;
    
    public Height() 
    {
        this.feet = 0;
        this.inches = 0;
    }
    
    public Height (int feet, int inches)
    {
        this.feet = feet;
        this.inches = inches;
    }
    
    public int getFeet() {
        return feet;
    }
    
    public void setFeet(int feet) {
        this.feet = feet;
    }
    
    public int getInches() {
        return inches;
    }
    
    public void setInches(int inches) {
        this.inches = inches;
    }
    public String toString()
    {
        return feet + "'" + inches + '"';
    }
}
