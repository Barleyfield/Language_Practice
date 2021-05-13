/*
    Grade.java

    실행하기 위해서는 GradeGUI.java 파일도 필요합니다.

    142694 윤이삭
    학생들의 석차를 구하여 보여주는 GUI 프로그램
    점수가 같으면 순위도 같게 설정.
    예 : 80,95,95,87,70 → 석차 4,1,1,3,5

 */
import javax.swing.JFrame;

public class Grade {
    public static void main(String[] args) {
        JFrame frame = new JFrame("GradeGUI");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GradeGUI panel = new GradeGUI();

        frame.getContentPane().add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
