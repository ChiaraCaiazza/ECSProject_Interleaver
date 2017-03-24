------------------------------------------------------------------------------ -
--Interleaver
--
--File name : interleaver.vhd
-- 
--Author: Chiara Caiazza	
------------------------------------------------------------------------------ -


Library IEEE;
Use IEEE.STD_LOGIC_1164.ALL;
Use IEEE.STD_LOGIC_ARITH.ALL;
Use IEEE.STD_LOGIC_UNSIGNED.ALL;   
use ieee.numeric_std.ALL;		 



---------------------------- Entity declaration  --------------------------------
entity interleaver is
  
	port(
		clk           : in std_logic;   		-- Processing clock 
       	reset         : in  std_logic;   		-- Asynchronous active high reset 		 	 
       	bit_in  : in std_logic;   				--  input bit	
       	bit_out : out std_logic 				--  output bit	 
    );													
	   
end interleaver;	




------------------ Architecture begins here  -----------------------------------------
architecture Behavioral of interleaver is


----------------------- signals declaration  ------------------------------------------		 
Begin	
	
  	process(clk, reset, bit_in)
	  
	  	--a implements the relation (actualIndex*3+45)mod 1024
	  	variable a: integer;
		--actual cycle# 
		--              [0-1023]    -> 1024 input cycle  (one  input bit for each cycle)
		--              [1024-2047] -> 1024 output cycle (one output bit for each cycle) 
		--              >=2048      -> reset
	  	variable actualIndex: integer;
		-- store the input bit at the index a
		variable memory: std_logic_vector(1023 downto 0);				   
	  
	  	begin	
		
			interleaver:
		
			-- high active reset
		    if reset = '1' then	 	 
					-- initialize actual index
				 	actualIndex:=0;
					-- initialize a
			  	  	a:=0;	
					bit_out<='Z';
						
					--all the bits in the array are equal to zero   
					for i in 0 to 1023 loop
						memory(i):='0';
					end loop;
				
			 
	    	elsif clk = '1' and clk'event then     			 
			-- In this case I read the input bit and i store it into the array 
			-- or I show an input bit depending on actualIndex 
					
					if actualIndex<1024 then
					-- I store the input bit into the array	in the a-th element
					
						--set the value for a
						a:=actualIndex*3;	
						a:= a+45;
										
						for i in 0 to 3 loop 
							if a>1023 then 	
								a:= a-1024;	 
							end if;	 
						end loop;
						
						--I want to store an input bit... 
						--the value on out is not a significant one
						bit_out<='Z';	
						-- I store the input bit
						memory(a):=bit_in;
						
						
				elsif actualIndex<2048 then
						-- I shown the output bit. actualIndex belongs to [1024-2047] 
						-- interval. If I subtract 1024 then it belongs to [0-1023] interval!
						bit_out<=memory(actualIndex-1024);
					
					
				elsif actualIndex>=2048 then
				-- I reset all the index and the memory!
				
						-- reset actual index
				 		actualIndex:=0;
						-- reset a
			  	  		a:=0;	
						--output bit is not significant anymore
						bit_out<='Z';
						
						--reset all the bits in the array 
						for i in 0 to 1023 loop
							memory(i):='0';
						end loop;	 
	
						
				end if;	
				
				--i inctrease actual index
				actualIndex:=actualIndex+1;	  
				
		    end if;	
			
  end process;	
  
end behavioral;	