# Worksheet D

### Sprint One

In our first sprint, I implemented raycasting to toggle the visibiliy of point lights. I also built our Github pages website, designing a minimalist theme to match the style of our game https://fingerguns.github.io/standby.github.io/ . Additionally I set up a facebook and twitter account to advertise our game throughout development, as well as a github repository to use whilst waiting for our SVN server. Finally I organised a meeting with the other programmers to plan and divide out tasks.

### Sprint Two

In our second sprint, I worked as a commuincator between the programmers and rest of our team, as not everybody was making it in to the daily Stand Ups. I implemented a basic pickup system and created a widget for the inventory, displayed on the viewport by pressing relevant keyboard button. However, on playtesting I needed to make some improvements to the system in the following sprint. Additionally I set up a function to toggle all lights in the map from one light switch, using raycasting. Finally, I set up audio activation by raycast and added blueprints by self and other programmers to game, as we were still waiting for the SVN server.

### Sprint Three

For our third sprint, I completed the pickup system, including; inventory widgets with slots to display item icons once picked up, spawn and deleting widget on viewport (rather than toggling visbility), picking up and destroying actors (namely keycards and axe). Although I added this to the game, members of are team have forgotten to update SVN before committing, meaning I will have to re-add the pickup system in the next sprint. I built matinee for opening and closing study door, which is only called if keycard is present in inventory when door is raycasted. To tidy the event graph and make it quicker to add new features, I set up raycast in its own function named 'Trace', enabling us to use it multiple times without repeating script. Additionaly I set up and organised a trello just for the programmers in our team, as we were  finding it diffiuclt to keep track of tasks in the group trello.

### Sprint Four

In sprint four, I added the ability to switch between five phone sceen widgets, using mouse cursor to select buttons. I also re-added the pickup system and door matinee, which had been saved over. To distract AI, we needed to implment explosions and breakage of household electrics, so I added a particle effect to the TV and fridge, triggered by raycast. I also implemented crouch so that our player is low down enough to hide under desks, however, this was also osaved over and in a later sprint wad added back in by John. All of the programmers in our team have tried to stress the importance in updating SVN before committing and to not upload Save files. Additionally I edited our website, adding screenshots and setting up a Youtube account ready for trailer. I also helped preapre for the trailer by fixing small bugs picked up by designiners and giving ideas for information to include in powerpoint.

### Sprint Five

During sprint five, I switched the door matinees to be triggered by trigger box overlap, rather than raycast, with the exception of the two doors requring keycards to activate. These had to be re-added, as again work had been saved over. An important job this sprint was to set up phone widget in world space, rather than in the viewport, we wanted to have the phone in the hand of th first person player, and I have been able to successfully add this. However, I need to add in functionaily to switch between different phone screens and trigger events with phone buttons. Finally I set up light switces to turn on only lights in the current room, rather than the whole house, but this needs to be re-added in the next sprint, as once again the work was saved over.

### Final Sprint

For our final sprint, I need to finish implementing the 2D phone widget in world space rather than displaying on viewport. Once completed, I then need to set up buttons on phone to trigger first person character animations, followed by raycast to actor and based on actor traced, trigger an event. I also need to add the light switches by room back into the game. Following this, polishing the game and fixing any bugs picked up in playtesting.
