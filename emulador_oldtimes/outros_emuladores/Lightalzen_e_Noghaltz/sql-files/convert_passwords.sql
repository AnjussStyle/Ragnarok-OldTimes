# conversor de passwords para criptografia MD5
# ATEN��O! 
# N�o � poss�vel retornar ao valor inicial ap�s transformar em MD5!!!

UPDATE `login` SET `user_pass`=MD5(`user_pass`);
