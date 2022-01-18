
package Model;

import java.util.ArrayList;


public class FootballPlayer extends Person implements TableMember
{
    private int number;
    private String position;

    public FootballPlayer(int number, String position, String inf_name, int inf_weight, String inf_hometown, String inf_highSchool, Height inf_height) {
        super(inf_name, inf_weight, inf_hometown, inf_highSchool, inf_height);
        this.number = number;
        this.position = position;
    }

    public FootballPlayer() {
        super();
        this.number = 0;
        this.position = "N/A";
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
        
    }

    @Override
    public String toString() {
        return super.toString() + " FootballPlayer {number=" + number + ", postion= "+ position + "}" ;
    }

    @Override
    public String getAttribute(int n) {
        ArrayList <String> attributes = new ArrayList<String>();
        attributes.add(String.valueOf(this.getNumber()));
        attributes.add(this.getName());
        attributes.add(this.getPosition());
        attributes.add(this.getHeight().toString());
        attributes.add(String.valueOf(this.getWeight()));
        attributes.add(this.getHometown());
        attributes.add(this.getHighSchool());
        return attributes.get(n);
    }

    @Override
    public ArrayList<String> getAttributes() {
        ArrayList <String> attributes = new ArrayList<String>();
        attributes.add(String.valueOf(this.getNumber()));
        attributes.add(this.getName());
        attributes.add(this.getPosition());
        attributes.add(this.getHeight().toString());
        attributes.add(String.valueOf(this.getWeight()));
        attributes.add(this.getHometown());
        attributes.add(this.getHighSchool());
        return attributes;
    }

    @Override
    public String getAttributeName(int n) {
        ArrayList <String> names = new ArrayList<String>();
        names.add("number");
        names.add("name");
        names.add("position");
        names.add("height");
        names.add("weight");
        names.add("hometown");
        names.add("highSchool");
        return names.get(n);
    }

    @Override
    public ArrayList<String> getAttributeNames() {
       ArrayList <String> names = new ArrayList<String>();
        names.add("number");
        names.add("name");
        names.add("position");
        names.add("height");
        names.add("weight");
        names.add("hometown");
        names.add("highSchool");
        return names;
    }
    
}
