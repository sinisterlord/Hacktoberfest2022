class Solution {
    public static ArrayList<Integer> findLeastGreater(int n, int[] arr) {
        // code here
       TreeMap<Integer,Integer> tm = new TreeMap<>();
       ArrayList<Integer> al = new ArrayList<>();
       for(int i=n-1;i>=0;i--){
           Map.Entry<Integer,Integer> x = tm.higherEntry(arr[i]);
           int val = x==null?-1:x.getKey();
           al.add(val);
           tm.put(arr[i],0);
       }
       Collections.reverse(al);
       return al;
    }
}
