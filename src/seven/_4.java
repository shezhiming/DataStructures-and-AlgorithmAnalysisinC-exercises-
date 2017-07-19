package seven;

public class _4 {
	
	public void xier(int[] array,int[] seqs){
		
		int num = 0,seq = 0;
		int i = 0,j = 0,tem = 0;
		for(seq = (seqs.length-1);seq >= 0;seq--){
			tem = seqs[seq];
			for(i = 0;i < array.length;i++){
				num = array[i];
				for(j = i;(j-tem) >= 0;j-=tem){
					if(num < array[j-tem]){
						array[j]  = array[j-tem];
					}else{
						break;
					}
					
				}
				array[j] = num;
			}
			
		}
	}

	public static void main(String args[]) { 
		long a=System.nanoTime();
		_4 instan = new _4();
		int[] array = {9,8,7,6,5,4,3,2,1};
		int[] seqs = {1,3,7};
		instan.xier(array,seqs);
		System.out.println("\r<br>Ö´ÐÐºÄÊ± : "+(System.nanoTime()-a)+" ns ");
		
	}
}
