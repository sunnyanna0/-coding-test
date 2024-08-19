import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String name;
        double point;
        String score1;
        double score2=0.0;
        double sum1=0.0, sum2=0.0;
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<20 ; i++){
            name=sc.next();
            point=sc.nextDouble();
            score1=sc.next();
            switch(score1) {

                case "A+":
                    score2=4.5;
                    break;
                case "A0":
                    score2=4.0;
                    break;
                case "B+":
                    score2=3.5;
                    break;
                case "B0":
                    score2=3.0;
                    break;
                case "C+":
                    score2=2.5;
                    break;
                case "C0":
                    score2=2.0;
                    break;
                case "D+":
                    score2=1.5;
                    break;
                case "D0":
                    score2=1.0;
                    break;
                case "F":
                    score2=0.0;
                    break;
                case "P":
                    continue;
            }
            sum1+=score2*point;
            sum2+=point;
        }
        System.out.println((double)sum1/(double) sum2);
    }
}