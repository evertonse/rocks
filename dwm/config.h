/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 4;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */

static int autostart_prefix_dot_config = 1; /*use home/.config/dwm/autostart.sh*/
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */

static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const char *fonts[] = { 
  "mono:pixelsize=12:antialias=true:autohint=true",
  "NotoColorEmoji:pixelsize=11:antialias=true:autohint=true", 
  "JetBrainsMonoNF:pixelsize=11:antialias=true:autohint=true" 
  "Lekton\\ Nerd\\ Font\\ Complete\\ Mono:pixelsize=12:antialias=true:autohint=true",
  "monospace:pixelsize=12:antialias=true:autohint=true",
  "Lekton\\ Nerd\\ Font\\ Complete\\ Mono.ttf:pixelsize=11:antialias=true:autohint=true",
  "Lekton Nerd Font Complete Mono.ttf:pixelsize=11:antialias=true:autohint=true",
  "JetbrainsMonoNerdFonts:pixelsize=11:antialias=true:autohint=true",
};
static const char dmenufont[]       = "monospace:size=11";

// static const char col_gray1[]      = "#222222";
// static const char col_gray2[]      = "#444444";
// static const char col_gray3[]      = "#bbbbbb";
//static const char col_gray4[]       = "#eeeeee";
//static const char col_cyan[]        = "#005577";

// static const char col_gray1[]       = "#222222";
// static const char col_gray2[]       = "#444444";
// static const char col_gray3[]       = "#bbbbbb";
// static const char col_gray4[]       = "#1b0b02";
// static const char col_cyan[]        = "#ebdbb2";

static const char col_gray1[]       = "#2D2D2D";
static const char col_tab_bg[]      = "#4E4E4E";
static const char col_tab_fg[]      = "#BBBBBB";
static const char col_gray2[]       = "#373737";
static const char col_gray3[]       = "#BBBBBB";
static const char col_gray4[]       = "#1E1E1E";
static const char col_cyan[]        = "#8db9e2";
static const char col_hov_bg[]      = "#4E4E4E";
static const char col_hov_fg[]      = "#9eCaF3";
static const char hid[]             = "#8db9e2";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { "#BBBBBB", col_gray4,  col_cyan  },
	[SchemeHov]  = { col_hov_fg, col_hov_bg,  col_cyan  },
	[SchemeHid]  = { col_cyan,  col_gray4, col_cyan  },
};
/* tagging */
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = { "","1", "2", "3", "4", "5", "6", "7", "8"};
// static const char *tags[] = { "'","1", "2", "3", "4", "5", "6", "7", "8"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "St",      NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ "Blueman", NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ "Google Chrome", NULL,     NULL,     1 << 7,         0,          1,           0,   -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};
static const XPoint stickyicon[]    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb    = {4,8};	/* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

/* layout(s) */
static const float mfact     = 0.58; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " [T] ", tile },    /* first entry is default */
	{ " [F] ", NULL },    /* no layout function means floating behavior */
	{ " [M] ", monocle},
};

/* key definitions */
#define SUPERKEY Mod4Mask
#define ALTKEY Mod1Mask

#if defined(WSL)
  #define MODKEY ALTKEY 
#else
  #define MODKEY SUPERKEY
#endif

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]     = { "dmenu_run", "-c", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]      = { "st", NULL };
static const char *wificmd[]      = { "st","nmtui", NULL };
static const char *explorercmd[]  = { "st","lf", NULL };
static const char *printcmd[]     = { "flameshot", "gui", NULL };
static const char *volumecmd[]    = { "st", "-e", "pulsemixer", NULL };
static const char *bluetoothcmd[]    = { "st", "-e", "bluetuith", NULL };
// static const char *volumecmd[]    = { "st", "-e", "pavucontrol", NULL };
// static const char *bluetoothcmd[] = { "source", "~/.config/sh/var.sh && blueman-manager", NULL };


#include "movestack.c"
#include "tagall.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
  { MODKEY|ShiftMask,             XK_F1,      tagall,        {.v = "F1"} },
  { MODKEY,                       XK_F1,      tagall,        {.v = "1"} }, 
  { MODKEY,                       XK_F8,      tagall,        {.v = "9"} }, 
	{ 0,                            XK_Print,  spawn,          {.v = printcmd} },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ ALTKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_apostrophe,      spawn,          {.v = termcmd, .f = 1} },
	{ MODKEY|ShiftMask,             XK_v,      spawn,          {.v = volumecmd} },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = wificmd} },
	{ MODKEY|ShiftMask,             XK_b,      spawn,          {.v = bluetoothcmd} },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          {.v = explorercmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,  {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_l,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
#if defined(MODKEY) && MODKEY == SUPERKEY
	{ MODKEY,                       XK_c,      killclient,     {0} },
#else
	{ MODKEY|ShiftMask,                       XK_c,      killclient,     {0} },
#endif
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY|ShiftMask,             XK_x,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_s,      show,           {0} },
	{ MODKEY|ShiftMask,             XK_s,      showall,        {0} },
	{ MODKEY|ShiftMask,             XK_g,      hide,           {0} },
	TAGKEYS(                        XK_apostrophe,             0)
	TAGKEYS(                        XK_1,                      1)
	TAGKEYS(                        XK_2,                      2)
	TAGKEYS(                        XK_3,                      3)
	TAGKEYS(                        XK_4,                      4)
	TAGKEYS(                        XK_5,                      5)
	TAGKEYS(                        XK_6,                      6)
	TAGKEYS(                        XK_7,                      7)
	TAGKEYS(                        XK_8,                      8)
	TAGKEYS(                        XK_9,                      9)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
