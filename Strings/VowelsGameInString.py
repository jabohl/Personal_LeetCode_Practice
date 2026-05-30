class Solution:
    def doesAliceWin(self, s: str) -> bool:
        
        
        def countVowels(val):
        
            count=0
            
            for i in val:
            
                if i=='a' or i=='e' or i=='i' or i=='o' or i=='u':
                
                    count+=1
            
            return count
        
        
        if countVowels(s)%2!=0:
        
            return True
        


        
        if countVowels(s)==0:
        
            return False
        
        
        
        while len(s)>0:
        
            
            for i in range( len(s)-1 , -1, -1 ):
        
            
                
                if countVowels( s[ :i+1 ] ) % 2 != 0:
                
                    
                    if not s:
                    
                        return False
                    
                    
                    s = s[ i+1: ]
                   
                elif countVowels(s[:i+1]) == 0:
                
                    if not s:
                    
                        return True
                    
                    
                    s = s[ 1: ]
                
                
                
                elif countVowels(s[:i+1])%2 == 0:
                
                    if not s:
                    
                        return True
                    
                    s = s[ i+1: ]
