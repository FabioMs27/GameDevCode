//Calling Collision and setting gravity
scr_collision();
hsp = 0;
vsp += grav;

//Energy meter
if (instance_exists(obj_energy))
energy -=1;

//animation 
if (place_meeting(x,y+1,obj_wall))
{
    sprite_index = spr_player_shoot;
}
else sprite_index = spr_player_jump;
