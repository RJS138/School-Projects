package Model;

import java.beans.XMLDecoder;
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.ArrayList;

public class FootballPlayerData implements TableData
{

    private ArrayList<TableMember> players;

    public FootballPlayerData()
    {
        players = new ArrayList<>();
        loadTable();
    }

    @Override
    public void loadTable()
    {
        ReadPlayersFromXML();
    }

    public void ReadPlayersFromXML()
    {
        try
        {
            FootballPlayer fp;
            XMLDecoder decoder;
            decoder = new XMLDecoder(new BufferedInputStream(new FileInputStream("FootballPlayerTable.xml")));
            fp = new FootballPlayer();
            while (fp != null)
            {
                try
                {
                    fp = (FootballPlayer) decoder.readObject();
                    players.add(fp);

                } catch (ArrayIndexOutOfBoundsException theend)
                {
                    //System.out.println("end of file");
                    break;
                }
            }
            decoder.close();
        } catch (Exception xx)
        {
            xx.printStackTrace();
        }
    }
    @Override
    public ArrayList<TableMember> getTable() {
        return players;
    }
    @Override
    public ArrayList<String> getHeaders() {
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
    @Override
    public ArrayList <String> getLine (int n){
        return players.get(n).getAttributes();
    }
    @Override
    public ArrayList <ArrayList<String>> getLines(int firstLine, int lastLine) {
        ArrayList<ArrayList<String>> lines = new ArrayList <ArrayList<String>> ();
        for ( int i = firstLine; i < lastLine; i++) {
            lines.add(this.getLine(firstLine));
        }
        return lines;
    }

}
