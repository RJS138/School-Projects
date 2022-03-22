package mapcounterfixme;

import java.util.Map;
import java.util.TreeMap;

public class MapCounterFixMe {

    public static void main(String[] args) {
        Map<String, Integer> wordCount = new TreeMap<>();
        String[] words = {"dog", "cat", "cat", "bird", "elk", 
            "bee", "dog", "cow", "bird", "cat", "elk", "dog", "bee", "elk", "cow"};
        
        for (String word : words) {
            if (wordCount.containsKey(word)){
                wordCount.put(word, wordCount.get(word) + 1);
            }
            else{
                wordCount.put(word, 1);
            }
        }
        System.out.println(wordCount);
    }
}


