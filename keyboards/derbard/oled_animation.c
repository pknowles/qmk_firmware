#include QMK_KEYBOARD_H

#if 0
static uint32_t oled32_read(uint16_t line)
{
    oled_buffer_reader_t current = oled_read_raw(line);
    uint32_t result =  (uint32_t)current.current_element[0] << 0;
    result |= (uint32_t)current.current_element[128] << 8;
    result |= (uint32_t)current.current_element[256] << 16;
    result |= (uint32_t)current.current_element[384] << 24;
    return result;
}

static uint32_t oled32_read_ptr(const uint8_t* ptr, uint16_t line)
{
    ptr += line;
    uint32_t result =  (uint32_t)ptr[0] << 0;
    result |= (uint32_t)ptr[128] << 8;
    result |= (uint32_t)ptr[256] << 16;
    result |= (uint32_t)ptr[384] << 24;
    return result;
}

static void oled32_write(uint32_t bits, uint16_t line)
{
    if(line >= OLED_DISPLAY_WIDTH)
    {
        oled_clear();
        oled_invert(true);
        return;
    }

    oled_write_raw_byte((uint8_t)(bits >> 0), line + 0);
    oled_write_raw_byte((uint8_t)(bits >> 8), line + 128);
    oled_write_raw_byte((uint8_t)(bits >> 16), line + 256);
    oled_write_raw_byte((uint8_t)(bits >> 24), line + 384);
}
#endif

static const char PROGMEM logo[] = {
    0x08, 0x0c, 0x0c, 0x0c, 0x0c, 0x1c, 0x1c, 0x7c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xe0, 0xe0, 
    0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x88, 0x08, 0x0c, 0x0c, 0x0c, 0x1c, 0x1c, 0xfc, 0xfc, 0xfc, 
    0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xc0, 0x00, 0x00, 0x80, 0x80, 
    0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x70, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0x1f, 0x07, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x20, 0xf0, 0xf8, 0xf8, 0xfc, 
    0xfe, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0x20, 0x70, 0xf8, 0xf8, 0xfc, 0xfe, 0xfe, 
    0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x20, 0x80, 0x80, 0x80, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xe0, 0xf0, 0xf8, 0xf8, 0xff, 0x7f, 0x3f, 0x1f, 0x1f, 0x03, 0x03, 0x03, 0x03, 
    0x07, 0x07, 0x0f, 0x3f, 0xff, 0xfe, 0xfc, 0xf8, 0xb0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 
    0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x70, 0xe0, 
    0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0x7e, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0d, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0x70, 0x3f, 0x0f, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x05, 0x0f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0x03, 0x07, 0x07, 0x0f, 0x1f, 0xff, 0xfe, 0xfe, 0xfc, 0x38, 0x10, 0x10, 0x38, 
    0xf8, 0xfc, 0xfe, 0xff, 0xff, 0x07, 0x7f, 0xff, 0xff, 0xfe, 0xf8, 0xe0, 0xc0, 0x80, 0x00, 0x00, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x1f, 0x0f, 0x03, 0x00, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xe0, 
    0x70, 0x78, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x30, 0x3f, 0x3f, 0x7f, 0x7f, 
    0xff, 0xf8, 0x3c, 0x1c, 0x0e, 0x0e, 0x06, 0x06, 0x06, 0x00, 0x10, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xff, 0xff, 0xff, 
    0x7f, 0x3f, 0x3f, 0x7c, 0x78, 0x78, 0xf8, 0xfe, 0x7f, 0x7f, 0x3f, 0x1f, 0x0e, 0x00, 0x10, 0x38, 
    0x3f, 0x7f, 0x7f, 0xff, 0xff, 0x7e, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x10, 
    0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1f, 
    0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3c, 0x38, 0xf8, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x30, 0x20, 0x00
};

//char anim_rain_masks[3][OLED_MATRIX_SIZE] = {};

// bad. don't do this
#define OLED_ALL_BLOCKS_MASK (((((OLED_BLOCK_TYPE)1 << (OLED_BLOCK_COUNT - 1)) - 1) << 1) | 1)
extern uint8_t         oled_buffer[OLED_MATRIX_SIZE];
extern OLED_BLOCK_TYPE oled_dirty;
#if 0
void anim_step(void)
{
    oled_set_cursor(0, 0);
    srand(0);
    memset(oled_buffer, 0, sizeof(oled_buffer));
    for(int i = 0; i < OLED_MATRIX_SIZE * 8; ++i)
    {
        char mask  = (1 << (i % 8));
        char pix   = pgm_read_byte(logo + (i / 8)) & mask;
        int  line  = (i / 8) % 128;
        int  start = line * 8 + 128 + rand() % 256;
        int  pos0  = MAX(line, start - (step * step) / 16);
        int  pos1  = MAX(line, start - ((step + 1) * (step + 1)) / 16);
        int  row   = (i / 8) / 128;
        if(pos1 < 128)
        {
            if(pos0 < 128)
            {
                int j = row * 128 + pos0;
                oled_buffer[j] &= ~pix;
                oled_dirty |= ((OLED_BLOCK_TYPE)1 << (j / OLED_BLOCK_SIZE));
            }
            int j = row * 128 + pos1;
            oled_buffer[j] |= pix;
            oled_dirty |= ((OLED_BLOCK_TYPE)1 << (j / OLED_BLOCK_SIZE));
        }
    }
    #if 0
    for(int i = 0; i < OLED_MATRIX_SIZE; ++i)
    {
        oled_buffer[i] = pgm_read_byte(logo + i);
        oled_dirty |= ((OLED_BLOCK_TYPE)1 << (i / OLED_BLOCK_SIZE));
    }
    #endif
    //oled_write_raw_P(logo, sizeof(logo));
}
#endif

#if 0
typedef struct __attribute__((__packed__)) {
    uint16_t position;
    uint32_t bit;
} LogoAnim;

static uint16_t fill_line = 0;
static uint16_t active_anim = 0;
static uint16_t active_anims = 0;

#define ANIMS 4
static LogoAnim anim[ANIMS] = {};

static void logo_anim_pixel(void)
{
    if(active_anims < 4)
    {
        uint32_t mask = (uint32_t)1 << ((active_anim + active_anims) % 32);
        anim[(active_anim + active_anims) % ANIMS].position = 127;
        anim[(active_anim + active_anims) % ANIMS].bit = oled32_read_ptr((uint8_t*)logo, fill_line) & mask;
        active_anims++;
    }
}

static void render_logo(void) {
    //oled_write_raw_P(logo, sizeof(logo));

    for (uint16_t i = active_anim; i < active_anim + active_anims; ++i)
    {
        uint16_t anim_idx = i % ANIMS;
        if(anim[anim_idx].position > fill_line)
        {
            oled32_write(0, anim[anim_idx].position--);
            if (anim[anim_idx].position == fill_line) {
                oled32_write(oled32_read(fill_line) | anim[anim_idx].bit, fill_line);
                #if 1
                active_anim++;
                active_anims--;
                if(active_anim >= 32)
                {
                    active_anim -= 32;
                    i -= 32;
                    fill_line++;
                    if(fill_line >= 128)
                    {
                        oled_clear();
                        fill_line = 0;
                    }
                }
                #endif
            } else {
                oled32_write(anim[anim_idx].bit, anim[anim_idx].position);
            }
        }
        else
        {
            break;
        }
    }
}

static uint32_t info_timeout_start = 0;
bool info_timed_out = true;
#endif

extern int mydebug;
int mydebug = 0;

static uint32_t last_event_time = 0;

static int anim_next = 0;
static bool anim_fill = true;

typedef struct __attribute__((__packed__)) {
    int pixel;
    int step;
    bool fill;
} LogoAnim;

#define ANIMS 8

static int activeAnim = 0;
static int activeAnims = 0;
static LogoAnim anims[ANIMS];

typedef struct {
    int x;
    int y;
} Pos;

bool logo_bit(int x, int y)
{
    int index = x + (y >> 3) * OLED_DISPLAY_WIDTH;
    char byte = pgm_read_byte(logo + index);
    return (byte & (1 << (y & 0x7))) != 0;
}

Pos anim_pos(LogoAnim anim) {
    Pos result;
    result.x    = anim.pixel % OLED_DISPLAY_WIDTH;
    int y_start = anim.fill ? 0 : anim.pixel / OLED_DISPLAY_WIDTH;
    result.y    = y_start + (anim.step * anim.step) / 64;
    return result;
}

Pos anim_pos_end(LogoAnim anim) {
    Pos result;
    result.x = anim.pixel % OLED_DISPLAY_WIDTH;
    result.y = anim.fill ? anim.pixel / OLED_DISPLAY_WIDTH : OLED_DISPLAY_HEIGHT;
    return result;
}

void anim_draw(LogoAnim anim, bool set)
{
    Pos pos = anim_pos(anim);
    oled_write_pixel(pos.x, pos.y, set);
}

void anim_finish(LogoAnim anim)
{
    if(anim.fill)
    {
        Pos pos = anim_pos_end(anim);
        oled_write_pixel(pos.x, pos.y, true);
    }
}

void anim_drop_at(int pixel, bool fill)
{
    int anim = (activeAnim + activeAnims) % ANIMS;
    if(activeAnims >= ANIMS)
    {
        anim_draw(anims[anim], false);
        anim_finish(anims[anim]);
        activeAnim = (activeAnim + 1) % ANIMS;
        activeAnims--;
    }
    anims[anim].pixel = pixel;
    anims[anim].step  = 0;
    anims[anim].fill  = fill;
    if(!fill)
    {
        anim_draw(anims[anim], false);
        anims[anim].step++;
    }
    anim_draw(anims[anim], true);
    activeAnims++;
}

bool anim_step(int anim)
{
    anim_draw(anims[anim], false);
    anims[anim].step += 1;
    Pos pos = anim_pos(anims[anim]);
    Pos end = anim_pos_end(anims[anim]);
    if (pos.y >= end.y) {
        anim_finish(anims[anim]);
        return true;
    } else {
        anim_draw(anims[anim], true);
        return false;
    }
}
void anim_drop(void)
{
    bool found = false;
    while(!found)
    {
        int x = anim_next % OLED_DISPLAY_WIDTH;
        x = (x & 0xfffa) | ((x & 1) << 2) | ((x & 4) >> 2);
        int y = OLED_DISPLAY_HEIGHT - anim_next / OLED_DISPLAY_WIDTH - 1;
        anim_next++;
        found = logo_bit(x, y);
        if (found) {
            int pixel = x + y * OLED_DISPLAY_WIDTH;
            anim_drop_at(pixel, anim_fill);
        }
        if (anim_next >= OLED_DISPLAY_WIDTH * OLED_DISPLAY_WIDTH) {
            anim_next = 0;
            anim_fill = !anim_fill;
        }
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_clear();
    #if 1
    oled_write_raw_P(logo, sizeof(logo));
    anim_fill = false;
    #endif
    return rotation;
}

bool oled_task_user(void)
{
    const int end = activeAnim + activeAnims;
    for(int i = activeAnim; i < end; ++i)
    {
        if (anim_step(i % ANIMS)) {
            for(int j = i; j > activeAnim; --j)
            {
                anims[j] = anims[j - 1];
            }
            ++activeAnim;
            --activeAnims;
        }
    }
    activeAnim = activeAnim % ANIMS;

    uint32_t elapsed = timer_elapsed32(last_event_time);
    if(elapsed > 3000 && elapsed < 300000)
    {
        if (rand() % 32 == 0)
            anim_drop();
    }
    return false;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record)
{
    last_event_time = timer_read32();

    if (record->event.pressed)
    {
        anim_drop();
    }
}