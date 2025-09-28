func largestAltitude(gain []int) int {
    ans:=0
    sum:=0
    for _,value:= range gain{
        sum+=value;
        ans=max(ans,sum)
    }
    return ans
}