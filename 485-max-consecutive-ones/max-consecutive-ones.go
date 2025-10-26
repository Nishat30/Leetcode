func findMaxConsecutiveOnes(nums []int) int {
    cnt:=0
    max_cnt:=0
    for _,i:= range(nums){
        if(i==1){
            cnt++;
        }else{
            if max_cnt<cnt {
                max_cnt=cnt;
            }
            cnt=0;
        }
    }
    max_cnt=max(max_cnt,cnt);
    return max_cnt;
}