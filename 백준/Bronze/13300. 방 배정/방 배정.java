import java.util.*;
import java.lang.*;
import java.io.*;

// class Student{
//     int s;
//     int y;
//     Student(int s, int y){
//         this.s = s;
//         this.y = y;
//     }
// }

class Room{
    int countPeople;
    int gender;
    int year;
    Room(int countPeople, int gender, int year){
        this.countPeople=countPeople;
        this.gender=gender;
        this.year=year;
    }
}

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int s, y;
        int answer = 0;
        ArrayList<Room> list = new ArrayList<>();
        
        for(int i=0 ; i<n ; i++){
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());

            boolean found = false;
            for(int j = 0; j < list.size(); j++) {
                Room currentRoom = list.get(j);
                
                if(currentRoom.gender == s && currentRoom.year == y) {
                    currentRoom.countPeople++;
                    found = true;
                    
                    // 방이 꽉 찼다면?
                    if(currentRoom.countPeople == k) {
                        answer++;
                        list.remove(j);
                    }
                    break; 
                }
            }

            if(!found) {
                if(k == 1) {
                    answer++;
                } else {
                    list.add(new Room(1, s, y));
                }
            }
        }

        answer += list.size();
        System.out.println(answer);
    }
}

// 같은 학년, 남/여
// 학생수 N
// 한 방에 배정할 수 있는 최대 인원수 K
// 성별, 학년
// 걍 처음부터 배열 돌아도 n이 1000