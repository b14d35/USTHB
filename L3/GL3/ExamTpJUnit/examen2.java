
public class examen2 {
	public int somme(int[][] mat){
		int s = 0;
		int n = mat.length;
		if(mat[0].length != n) return 0;
		for(int i=0;i<n;i++){
			System.out.println(i + " " + (i));
			s += mat[i][i];
			s += mat[i][n-1-i];
		}
		return s;
	}
	
	public int[][] colonne(int[][] mat){
		int n = mat.length;
		int m = mat[0].length;
		int[] s = new int[m];
		for(int j=0; j<m; j++){
			for(int i=0; i<n; i++){
				s[j] += mat[i][j];
			}
		}
		int min=s[0], max=s[0], pmin=0, pmax=0;
		for(int i=1; i<m; i++){
			if(s[i]>max){
				max = s[i];
				pmax = i;
			}
			if(s[i]<min){
				min = s[i];
				pmin = i;
			}
		}
		if(min != max){
			for(int i=0; i<n; i++){
				int temp = mat[i][pmin];
				mat[i][pmin] = mat[i][pmax];
				mat[i][pmax] = temp;
			}
		}
		return mat;
	}
}
