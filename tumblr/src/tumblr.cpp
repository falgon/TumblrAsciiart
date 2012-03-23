#include<array>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<miko/rall_cout.hpp>

template<class Range,class Function>
void replace(Range& s,const char* src,
                const char* dst,Function f)
{
	const size_t src_len=strlen(src);
	const size_t dst_len=strlen(dst);

	for(size_t c=0; c<s.size(); ++c){
		for(std::string::size_type i=0; 
				(i=s[c].find(src,i,src_len))!=std::string::npos;
			i+=dst_len){
		s[c].replace(i,src_len,dst,dst_len);
		f(s);
		}
	}
}

int main()
{
	std::array<std::string,11> ar{
"    .                                 .o8       oooo                \n",
"  .o8                                \"888       `888               \n",
".o888oo oooo  oooo  ooo. .oo.  .oo.   888oooo.   888  oooo d8b     \n",
"  888   `888  `888  `888P\"Y88bP\"Y88b  d88' `88b  888  `888\"\"8P     \n",
"  888    888   888   888   888   888  888   888  888   888         \n",
"  888 .  888   888   888   888   888  888   888  888   888    .o.  \n",
"  \"888\"  `V88V\"V8P' o888o o888o o888o `Y8bod8P' o888o d888b   Y8P  \n"
        };
	replace(ar," ","0",[](const std::array<std::string,11>&){});
	replace(ar,"0"," ",[](const std::array<std::string,11>& s){
                        system("cls");
                        miko::rall_cout<<s;});
}
