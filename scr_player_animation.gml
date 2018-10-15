//Animation
if (sprite_index == spr_player_idle) image_speed = 0.16;
if (sprite_index == spr_player_run) image_speed = 0.25;
if (sprite_index == spr_player_runshot) image_speed = 0.25;
if (sprite_index == spr_player_shoot or sprite_index == spr_player_jump ) image_speed = 0;


//direction
if (move = 1) image_xscale = 1;
if (move = -1) image_xscale = -1;


if (isShoot = false)
{
    if (place_meeting(x,y+1,obj_wall))
    {
        if (move != 0)
        { 
            sprite_index = spr_player_run;
        } 
        else
        { 
            sprite_index = spr_player_idle;
        }
    
    }
    
    else
    {
        if (grounded = false) sprite_index = spr_player_jump;
    }
}

else 
{
    if (place_meeting(x,y+1,obj_wall))
    {
        if (move != 0)
        { 
            sprite_index = spr_player_runshot;
        } 
        else
        { 
            sprite_index = spr_player_shoot;
        }
    
    }
    
    else
    {
        if (grounded = false) sprite_index = spr_player_jump;
    }
}

