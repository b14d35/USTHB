package moyenne;

public class Function {
	public float moyenne(float x[], int N){
		float sum = 0;
		for(int i=0;i<N;i++){
			sum+=x[i];
		}
		return (float)sum/N;
	}
}
