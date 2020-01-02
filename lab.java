package work;
import javax.swing.*;
public class lab {
	public static void main(String[] args) {
		String i;
		i=JOptionPane.showInputDialog("Enter number students : ");
		int ii = Integer.parseInt(i);
		String infoST[][] = new String[ii][9];
		for(int n=0;n<ii;n++) {
			getdata(infoST,n);
			total(infoST,n);
			grade(infoST,n);
		}
		display(infoST,ii);
		System.exit( 0 );
	}
	public static void getdata(String infoST[][],int i) {
		int put , check;
		infoST[i][0]=JOptionPane.showInputDialog("Enter name students["+(i+1)+"] : ");
		/*infoST[i][1]= String.valueOf(1 + ( int ) ( Math.random() * 15 ));
		infoST[i][2]= String.valueOf(1 + ( int ) ( Math.random() * 5 ));
		infoST[i][3]= String.valueOf(1 + ( int ) ( Math.random() * 30 ));
		infoST[i][4]= String.valueOf(1 + ( int ) ( Math.random() * 30 ));
		infoST[i][5]= String.valueOf(1 + ( int ) ( Math.random() * 10 ));
		infoST[i][6]= String.valueOf(1 + ( int ) ( Math.random() * 10 ));*/
		do{
			check = 0;
			infoST[i][1]=JOptionPane.showInputDialog("Enter homework score students["+(i+1)+"] : ");
			put = Integer.parseInt(infoST[i][1]);
			if(put>15)
			{JOptionPane.showMessageDialog( null,"Score must be less 15","Cation!",JOptionPane.INFORMATION_MESSAGE );
				check = 1;}
		}while(check == 1);
		do{
			infoST[i][2]=JOptionPane.showInputDialog("Enter Attend class score students["+(i+1)+"] : ");
			put = Integer.parseInt(infoST[i][2]);
			if(put>5)
			{JOptionPane.showMessageDialog( null,"Score must be less 5","Cation!",JOptionPane.INFORMATION_MESSAGE );
			check = 1;}
		}while(check == 1);
		do{
			infoST[i][3]=JOptionPane.showInputDialog("Enter Midterm score students["+(i+1)+"] : ");
			put = Integer.parseInt(infoST[i][3]);
			if(put>30)
			{JOptionPane.showMessageDialog( null,"Score must be less 30","Cation!",JOptionPane.INFORMATION_MESSAGE );
			check = 1;}
			}while(check == 1);
		do{
			infoST[i][4]=JOptionPane.showInputDialog("Enter Final score students["+(i+1)+"] : ");
			put = Integer.parseInt(infoST[i][4]);
			if(put>30)
			{JOptionPane.showMessageDialog( null,"Score must be less 30","Cation!",JOptionPane.INFORMATION_MESSAGE );
			check = 1;}
		}while(check == 1);
		do{
			infoST[i][5]=JOptionPane.showInputDialog("Enter Assign score students["+(i+1)+"] : ");
			put = Integer.parseInt(infoST[i][5]);
			if(put>10)
			{JOptionPane.showMessageDialog( null,"Score must be less 10","Cation!",JOptionPane.INFORMATION_MESSAGE );
			check = 1;}
		}while(check == 1);
		do{
			infoST[i][6]=JOptionPane.showInputDialog("Enter Test score students["+(i+1)+"] : ");
			put = Integer.parseInt(infoST[i][6]);
			if(put>10)
			{JOptionPane.showMessageDialog( null,"Score must be less 10","Cation!",JOptionPane.INFORMATION_MESSAGE );
			check = 1;}
		}while(check == 1);
	}
	public static void total(String infoST[][],int i) {
		int t,total=0;
		for(int n=1;n<=6;n++) {
			t = Integer.parseInt(infoST[i][n]);
			total+=t;
		}
		infoST[i][7]=String.valueOf(total);
	}
	public static void grade(String infoST[][],int i) {
		int TScore=Integer.parseInt(infoST[i][7]);
		if(TScore>=80)infoST[i][8]="A";
		else if(TScore>=70)infoST[i][8]="B";
		else if(TScore>=60)infoST[i][8]="C";
		else if(TScore>=50)infoST[i][8]="D";
		else infoST[i][8]="F";
	}
	public static void display(String infoST[][],int ii) {
		String out1;
		out1 = "Name\tHW\tClass\tMid\tFinal\tAssign\tTest\tTotal\tGrade\n";
		for(int n=0;n<ii;n++) {
			for(int m=0;m<9;m++)out1 += infoST[n][m]+"\t";
			out1 += "\n";
		}
		JTextArea output = new JTextArea();
		output.setText(out1);
		JOptionPane.showMessageDialog( null,output,"Result",JOptionPane.INFORMATION_MESSAGE );
	}

}
