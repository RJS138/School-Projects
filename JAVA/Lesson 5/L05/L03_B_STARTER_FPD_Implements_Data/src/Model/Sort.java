
package Model;

import java.util.ArrayList;

public class Sort {
    private ArrayList <TableMember> list;
    
    public Sort (ArrayList<TableMember> list) {
        this.list = list;
    }
    public ArrayList<TableMember> getList() {
        return list;
    }
    public void setList(ArrayList<TableMember> list) {
        this.list = list; 
    }
    
    public void sortByName() {
        for( int i = 0; i < list.size(); i++) {
            int firstAlphaIndex = i;
            for (int j = 1; j<list.size(); j++) {
                String [] name = list.get(i).getAttribute(1).split(" ");
                String [] name2 = list.get(j).getAttribute(1).split(" ");
                if (name[1].compareTo(name2[1]) > 0) {
                    firstAlphaIndex = j;
                }
            }
            if (firstAlphaIndex != i) {
                FootballPlayer temp = (FootballPlayer) list.get(i);
                list.set(i, list.get(firstAlphaIndex));
                list.set(firstAlphaIndex, temp);
            }
        }
    }
    
    public void sortByHeight() {
        for (int i= 0; i <list.size(); i++ ){
            int firstAlphaIndex = i; 
            for (int j = 1; j< list.size(); j++) {
                if (list.get(i).getAttribute(3).charAt(0)<= list.get(j).getAttribute(3).charAt(0) && list.get(i).getAttribute(3).charAt(2) < list.get(j).getAttribute(3).charAt(2)){
                    firstAlphaIndex = j;
                }
            }
            if (firstAlphaIndex != i) {
                FootballPlayer temp = (FootballPlayer) list.get(i);
                list.set(i, list.get(firstAlphaIndex));
                list.set(firstAlphaIndex, temp);
            }
        }
    }
}
