func sorting(s string) string {
	chars := strings.Split(s, "")
	sort.Strings(chars)
	return strings.Join(chars, "")
    }
func removeAnagrams(words []string) []string {
    var ans[]string
    for _,i := range words{
        if(len(ans)==0){
            ans= append(ans,i);
        }else{
            prev:=sorting(ans[len(ans)-1])
            curr:=sorting(i)
            if(prev!=curr){
                ans=append(ans,i)
            }
        }
    }
    return ans;
}