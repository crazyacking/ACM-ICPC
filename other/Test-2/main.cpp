public class Solution
{
    public  int maxArea(int[] height)
    {
        if ( (height == null) || (height.length <= 1) )
            return 0 ;
        int result = 0 ;
        ArrayList<Integer> seq = new ArrayList<Integer>();
        seq.add(new Integer(0));
        for (int i = 1 ; i < height.length; i++)
        {
            for ( Integer idx : seq )
            {
                int ht = height[i] > height[idx.intValue()] ? height[idx.intValue()] : height[i] ;
                int area = (i - idx.intValue()) * ht ;
                if ( area > result ) result = area ;
            }
            int lastIdx = seq.get(seq.size() - 1).intValue();
            if ( height[i] > height[lastIdx])
            {
                seq.add(new Integer(i)) ;
            }
        }
        return result ;

    }
}

public  int maxArea(int[] height)
{
    if ( (height == null) || (height.length <= 1) )
        return 0 ;
    int result = 0 ;
    ArrayList<Integer> seq = new ArrayList<Integer>();
    seq.add(new Integer(0));
    for (int i = 1 ; i < height.length; i++)
    {
        for ( Integer idx : seq )
        {
            int ht = height[i] > height[idx.intValue()] ? height[idx.intValue()] : height[i] ;
            int area = (i - idx.intValue()) * ht ;
            if ( area > result ) result = area ;
        }
        int lastIdx = seq.get(seq.size() - 1).intValue();
        if ( height[i] > height[lastIdx])
        {
            seq.add(new Integer(i)) ;
        }
    }
    return result ;

}
