/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab4;

import com.algorithmia.*;
import com.algorithmia.algo.*;
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {


        String input = "{\n\"document\": \"I really like Algorithmia!\"\n"}";
        AlgorithmiaClient client = Algorithmia.client("YOUR_API_KEY");
        Algorithm algo = client.algo("algo://nlp/SentimentAnalysis/1.0.3");
        AlgoResponse result = algo.pipeJson(input);
        System.out.println(result.asJsonString());
    }

}