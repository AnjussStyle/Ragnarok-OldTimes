<?
include "readfile";
echo '<center>';

$mobc = str_replace('mob_get_random_id: Invalid type (%d) of random monster.','mob_get_random_id: Tipo inv�lido (%d) de monstro rand�mico.',$mobc);

$mobc = str_replace('mob_spawn_guardian: Invalid guardian index %d for guardian %d (castle map %s)','mob_spawn_guardian: Guardi�o inv�lido %d para guardi�o %d (castle map %s)',$mobc);

$mobc = str_replace('mob_spawn_guardian: Spawning %d guardians in position %d (castle map %s)','mob_spawn_guardian: Spawning %d guardi�es na posi��o %d (castle map %s)',$mobc);

$mobc = str_replace('mob_spawn_guardian: No castle set at map %s','mob_spawn_guardian: Nenhum castelo setado no mapa %s',$mobc);

$mobc = str_replace('mob_spawn_guardian: Spawning guardian %d on a castle with no guild (castle map %s)','mob_spawn_guardian: Spawning guardi�o %d em um castelo sem nenhum Cl� (castle map %s)',$mobc);

$mobc = str_replace('mob_spawn_guardian: Spawning guardian in position %d which already has a guardian (castle map %s)','mob_spawn_guardian: Spawning guardi�o na posi��o %d que j� tem um guardi�o (castle map %s)',$mobc);

$mobc = str_replace('MOB cant move. random spawn %d, class = %d','MOB n�o pode se mecher. spawn rand�mico %d, class = %d',$mobc);

$fp = fopen($mobc2, 'w');
if (!fwrite($fp, $mobc)) {
echo "<font color=\"red\">O arquivo mob.c n�o foi convertido</font>";
}
echo "<font color=\"green\">O arquivo mob.c foi convertido</font>";
fclose($fp);

echo '</center>';
?>