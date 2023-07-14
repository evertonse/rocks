//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	/* {"⌨", "/home/excyber/.local/bin/statusbar/sb-kbselect", 0, 30}, */
	// {"", "cat /tmp/recordingicon 2>/dev/null",	0,	9},
	// {"",	"/home/excyber/.local/bin/statusbar/sb-tasks",	10,	26},
	/* {"",	"/home/excyber/.local/bin/statusbar/sb-music",	0,	11}, */
	// {"",	"/home/excyber/.local/bin/statusbar/sb-pacpackages",	0,	8},
	// {"",	"/home/excyber/.local/bin/statusbar/sb-news",		0,	6},
	/* {"",	"/home/excyber/.local/bin/statusbar/sb-price xmr Monero 🔒 24",			9000,	24}, */
	/* {"",	"/home/excyber/.local/bin/statusbar/sb-price eth Ethereum 🍸 23",	9000,	23}, */
	/* {"",	"/home/excyber/.local/bin/statusbar/sb-price btc Bitcoin 💰 21",				9000,	21}, */
	// {"",	"/home/excyber/.local/bin/statusbar/sb-torrent",	20,	7},
	/* {"",	"/home/excyber/.local/bin/statusbar/sb-memory",	10,	14}, */
	/* {"",	"/home/excyber/.local/bin/statusbar/sb-cpu",		10,	18}, */
	/* {"",	"/home/excyber/.local/bin/statusbar/sb-moonphase",	18000,	17}, */
	// {"",	"/home/excyber/.local/bin/statusbar/sb-doppler",	0,	13},
	// {"",	"/home/excyber/.local/bin/statusbar/sb-forecast",	18000,	5},
	// {"",	"/home/excyber/.local/bin/statusbar/sb-mailbox",	180,	12},
	// {"",	"/home/excyber/.local/bin/statusbar/sb-nettraf",	1,	16},
	// {"",	"/home/excyber/.local/bin/statusbar/sb-volume",	0,	10},
	// {"",	"/home/excyber/.local/bin/statusbar/sb-battery",	5,	3},
	// {"",	"/home/excyber/.local/bin/statusbar/sb-clock",	60,	1},
	// {"",	"/home/excyber/.local/bin/statusbar/sb-internet",	5,	4},
	/* {"",	"/home/excyber/.local/bin/statusbar/sb-iplocate", 0,	27}, */
	// {"",	"/home/excyber/.local/bin/statusbar/sb-help-icon",	0,	15},
  {" ", "date +\"%T\"", 1 ,0},
	// {" Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	10,		0},
 //  {""  , "~/.local/bin/statusbar/timerunning"                , 60 , 0} ,
 //  {""  , "~/.local/bin/statusbar/cpu_usage"                  , 5  , 0} ,
 //  {""  , "~/.local/bin/statusbar/bandwidth"                  , 5  , 4} ,
   {""  , "~/.local/bin/statusbar/volume"                     , 5  , 0} ,
   {":", "~/.local/bin/statusbar/battery | tr \'\n\' \' \' " , 5  , 0},
   {""  , "~/.local/bin/statusbar/clock"                      , 1  , 0} ,
    {"",    "/home/excyber/.local/bin/statusbar/sb-nettraf",       1,  7},
   // {"",    "/home/excyber/.local/bin/statusbar/sb-internet",      60, 4},
  // {"",    "/home/excyber/.local/bin/statusbar/sb-cpu",           15, 6},
   {"",    "/home/excyber/.local/bin/statusbar/sb-backlight",     0,  5},
  //  {"",    "/home/excyber/.local/bin/statusbar/sb-volume",        0,  3},
  //  {"",    "/home/excyber/.local/bin/statusbar/sb-battery",       60, 2},
  //   {"",    "/home/excyber/.local/bin/statusbar/sb-clock",         1, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char *delim = "   ";
// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
