
void elfDrawHorGradient(int x, int y, int width, int height, elfColor col1, elfColor col2)
{
	float *vertexBuffer;

	vertexBuffer = (float*)gfxGetVertexDataBuffer(eng->gradientVertexData);

	vertexBuffer[0] = x;
	vertexBuffer[1] = y+height;
	vertexBuffer[2] = 0.0f;
	vertexBuffer[3] = x;
	vertexBuffer[4] = y;
	vertexBuffer[5] = 0.0f;
	vertexBuffer[6] = x+width;
	vertexBuffer[7] = y+height;
	vertexBuffer[8] = 0.0f;
	vertexBuffer[9] = x+width;
	vertexBuffer[10] = y;
	vertexBuffer[11] = 0.0f;

	vertexBuffer = gfxGetVertexDataBuffer(eng->gradientColorData);

	vertexBuffer[0] = col1.r;
	vertexBuffer[1] = col1.g;
	vertexBuffer[2] = col1.b;
	vertexBuffer[3] = col1.a;
	vertexBuffer[4] = col2.r;
	vertexBuffer[5] = col2.g;
	vertexBuffer[6] = col2.b;
	vertexBuffer[7] = col2.a;
	vertexBuffer[8] = col1.r;
	vertexBuffer[9] = col1.g;
	vertexBuffer[10] = col1.b;
	vertexBuffer[11] = col1.a;
	vertexBuffer[12] = col2.r;
	vertexBuffer[13] = col2.g;
	vertexBuffer[14] = col2.b;
	vertexBuffer[15] = col2.a;

	gfxDrawVertexArray(eng->gradientVertexArray, 4, GFX_TRIANGLE_STRIP);
}

void elfDrawBorder(int x, int y, int width, int height, elfColor col)
{
	float *vertexBuffer;

	vertexBuffer = (float*)gfxGetVertexDataBuffer(eng->gradientVertexData);

	vertexBuffer[0] = x;
	vertexBuffer[1] = y+height;
	vertexBuffer[2] = 0.0f;
	vertexBuffer[3] = x;
	vertexBuffer[4] = y;
	vertexBuffer[5] = 0.0f;
	vertexBuffer[6] = x+width;
	vertexBuffer[7] = y;
	vertexBuffer[8] = 0.0f;
	vertexBuffer[9] = x+width;
	vertexBuffer[10] = y+height;
	vertexBuffer[11] = 0.0f;

	vertexBuffer = gfxGetVertexDataBuffer(eng->gradientColorData);

	vertexBuffer[0] = col.r;
	vertexBuffer[1] = col.g;
	vertexBuffer[2] = col.b;
	vertexBuffer[3] = col.a;
	vertexBuffer[4] = col.r;
	vertexBuffer[5] = col.g;
	vertexBuffer[6] = col.b;
	vertexBuffer[7] = col.a;
	vertexBuffer[8] = col.r;
	vertexBuffer[9] = col.g;
	vertexBuffer[10] = col.b;
	vertexBuffer[11] = col.a;
	vertexBuffer[12] = col.r;
	vertexBuffer[13] = col.g;
	vertexBuffer[14] = col.b;
	vertexBuffer[15] = col.a;

	gfxDrawVertexArray(eng->gradientVertexArray, 4, GFX_LINE_LOOP);
}

void elfDrawHorGradientBorder(int x, int y, int width, int height, elfColor col1, elfColor col2)
{
	float *vertexBuffer;

	vertexBuffer = gfxGetVertexDataBuffer(eng->gradientVertexData);

	vertexBuffer[0] = x;
	vertexBuffer[1] = y+height;
	vertexBuffer[2] = 0.0f;
	vertexBuffer[3] = x;
	vertexBuffer[4] = y;
	vertexBuffer[5] = 0.0f;
	vertexBuffer[6] = x+width;
	vertexBuffer[7] = y;
	vertexBuffer[8] = 0.0f;
	vertexBuffer[9] = x+width;
	vertexBuffer[10] = y+height;
	vertexBuffer[11] = 0.0f;

	vertexBuffer = gfxGetVertexDataBuffer(eng->gradientColorData);

	vertexBuffer[0] = col1.r;
	vertexBuffer[1] = col1.g;
	vertexBuffer[2] = col1.b;
	vertexBuffer[3] = col1.a;
	vertexBuffer[4] = col2.r;
	vertexBuffer[5] = col2.g;
	vertexBuffer[6] = col2.b;
	vertexBuffer[7] = col2.a;
	vertexBuffer[8] = col2.r;
	vertexBuffer[9] = col2.g;
	vertexBuffer[10] = col2.b;
	vertexBuffer[11] = col2.a;
	vertexBuffer[12] = col1.r;
	vertexBuffer[13] = col1.g;
	vertexBuffer[14] = col1.b;
	vertexBuffer[15] = col1.a;

	gfxDrawVertexArray(eng->gradientVertexArray, 4, GFX_LINE_LOOP);
}

ELF_API const char* ELF_APIENTRY elfGetGuiObjectName(elfGuiObject* object)
{
	return object->name;
}

ELF_API elfVec2i ELF_APIENTRY elfGetGuiObjectPosition(elfGuiObject* object)
{
	return object->relPos;
}

ELF_API elfVec2i ELF_APIENTRY elfGetGuiObjectSize(elfGuiObject* object)
{
	elfVec2i size;

	size.x = object->width;
	size.y = object->height;

	return size;
}

ELF_API elfColor ELF_APIENTRY elfGetGuiObjectColor(elfGuiObject* object)
{
	return object->color;
}

ELF_API unsigned char ELF_APIENTRY elfGetGuiObjectVisible(elfGuiObject* object)
{
	return object->visible;
}

ELF_API elfScript* ELF_APIENTRY elfGetGuiObjectScript(elfGuiObject* object)
{
	return object->script;
}

ELF_API int ELF_APIENTRY elfGetGuiObjectEvent(elfGuiObject* object)
{
	return object->event;
}

ELF_API void ELF_APIENTRY elfSetGuiObjectPosition(elfGuiObject* object, float x, float y)
{
	object->relPos.x = x;
	object->relPos.y = y;
	elfRecalcGuiObject(object);
}

ELF_API void ELF_APIENTRY elfSetGuiObjectColor(elfGuiObject* object, float r, float g, float b, float a)
{
	object->color.r = r;
	object->color.g = g;
	object->color.b = b;
	object->color.a = a;
}

ELF_API void ELF_APIENTRY elfSetGuiObjectVisible(elfGuiObject* object, unsigned char visible)
{
	object->visible = !visible == ELF_FALSE;
}

ELF_API void ELF_APIENTRY elfSetGuiObjectScript(elfGuiObject* object, elfScript* script)
{
	if(object->script) elfDecRef((elfObject*)object->script);
	object->script = script;
	if(object->script) elfIncRef((elfObject*)object->script);
}

ELF_API elfLabel* ELF_APIENTRY elfCreateLabel(elfGuiObject* parent, const char *name, int x, int y, const char *text)
{
	elfLabel* label;

	label = (elfLabel*)malloc(sizeof(elfLabel));
	memset(label, 0x0, sizeof(elfLabel));
	label->objType = ELF_LABEL;
	label->objDestr = elfDestroyLabel;

	label->color.r = label->color.g = label->color.b = label->color.a = 1.0f;
	label->visible = ELF_TRUE;

	if(name) label->name = elfCreateString(name);

	elfSetGuiObjectPosition((elfGuiObject*)label, x, y);
	elfSetLabelFont(label, eng->guiFont);
	elfSetLabelText(label, text);
	elfAddGuiObject(parent, (elfGuiObject*)label);

	elfIncObj(ELF_LABEL);

	return label;
}

void elfDestroyLabel(void* data)
{
	elfLabel* label = (elfLabel*)data;

	if(label->name) elfDestroyString(label->name);
	if(label->text) elfDestroyString(label->text);

	if(label->font) elfDecRef((elfObject*)label->font);

	free(label);

	elfDecObj(ELF_LABEL);
}

void elfDrawLabel(elfLabel* label, gfxShaderParams* shaderParams)
{
	if(!label->visible || !label->font || !label->text) return;

	gfxSetColor(&shaderParams->materialParams.diffuseColor, label->color.r, label->color.g, label->color.b, label->color.a);
	elfDrawString(label->font, label->text, label->pos.x, label->pos.y, shaderParams);
	shaderParams->textureParams[0].texture = NULL;
}

void elfRecalcLabel(elfLabel* label)
{
	if(label->font)
	{
		label->height = label->font->size;
		if(label->text)
		{
			label->width = elfGetStringWidth(label->font, label->text);
		}
	}
	else
	{
		label->height = 0;
		label->width = 0;
	}
}

ELF_API elfFont* ELF_APIENTRY elfGetLabelFont(elfLabel* label)
{
	return label->font;
}

ELF_API const char* ELF_APIENTRY elfGetLabelText(elfLabel* label)
{
	return label->text;
}

ELF_API void ELF_APIENTRY elfSetLabelFont(elfLabel* label, elfFont* font)
{
	if(label->font) elfDecRef((elfObject*)label->font);
	label->font = font;
	if(label->font) elfIncRef((elfObject*)label->font);
	elfRecalcGuiObject((elfGuiObject*)label);
}

ELF_API void ELF_APIENTRY elfSetLabelText(elfLabel* label, const char* text)
{
	if(label->text) elfDestroyString(label->text);
	label->text = elfCreateString(text);
	elfRecalcGuiObject((elfGuiObject*)label);
}

ELF_API elfButton* ELF_APIENTRY elfCreateButton(elfGuiObject* parent, const char* name, int x, int y, int width, int height, const char* text)
{
	elfButton* button;

	button = (elfButton*)malloc(sizeof(elfButton));
	memset(button, 0x0, sizeof(elfButton));
	button->objType = ELF_BUTTON;
	button->objDestr = elfDestroyButton;

	button->color.r = button->color.g = button->color.b = button->color.a = 1.0f;
	button->visible = ELF_TRUE;

	if(name) button->name = elfCreateString(name);

	elfSetGuiObjectPosition((elfGuiObject*)button, x, y);
	elfSetButtonFont(button, eng->guiFont);
	button->width = width;
	button->height = height;
	elfSetButtonText(button, text);
	elfAddGuiObject(parent, (elfGuiObject*)button);

	elfIncObj(ELF_BUTTON);

	return button;
}

void elfDestroyButton(void* data)
{
	elfButton* button = (elfButton*)data;

	if(button->name) elfDestroyString(button->name);

	if(button->text) elfDestroyString(button->text);
	if(button->font) elfDecRef((elfObject*)button->font);
	if(button->off) elfDecRef((elfObject*)button->off);
	if(button->over) elfDecRef((elfObject*)button->over);
	if(button->on) elfDecRef((elfObject*)button->on);

	if(button->script) elfDecRef((elfObject*)button->script);

	free(button);

	elfDecObj(ELF_BUTTON);
}

void elfDrawButton(elfButton* button, gfxShaderParams* shaderParams)
{
	if(!button->visible) return;

	gfxSetColor(&shaderParams->materialParams.diffuseColor, button->color.r, button->color.g, button->color.b, button->color.a);

	if(!button->off)
	{
		elfColor col1, col2;

		shaderParams->renderParams.vertexColor = ELF_TRUE;
		gfxSetColor(&shaderParams->materialParams.diffuseColor, 1.0f, 1.0f, 1.0f, 1.0f);
		gfxSetShaderParams(shaderParams);

		if(button->state == ELF_OFF) {col1.r = col1.g = col1.b = 0.40f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.25f; col2.a = 1.0f;}
		else if(button->state == ELF_OVER) {col1.r = col1.g = col1.b = 0.50f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.35f; col2.a = 1.0f;}
		else if(button->state == ELF_ON) {col1.r = col1.g = col1.b = 0.35f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.20f; col2.a = 1.0f;}
		elfDrawHorGradient(button->pos.x, button->pos.y+button->height/2, button->width, button->height/2, col1, col2);

		if(button->state == ELF_OFF) {col1.r = col1.g = col1.b = 0.20f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.10f; col2.a = 1.0f;}
		else if(button->state == ELF_OVER) {col1.r = col1.g = col1.b = 0.30f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.20f; col2.a = 1.0f;}
		else if(button->state == ELF_ON) {col1.r = col1.g = col1.b = 0.15f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.05f; col2.a = 1.0f;}
		elfDrawHorGradient(button->pos.x, button->pos.y, button->width, button->height/2, col1, col2);

		if(button->state == ELF_OFF) {col1.r = col1.g = col1.b = 0.40f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.20f; col2.a = 1.0f;}
		else if(button->state == ELF_OVER) {col1.r = col1.g = col1.b = 0.50f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.30f; col2.a = 1.0f;}
		else if(button->state == ELF_ON) {col1.r = col1.g = col1.b = 0.35f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.15f; col2.a = 1.0f;}
		elfDrawHorGradientBorder(button->pos.x, button->pos.y, button->width, button->height, col1, col2);

		shaderParams->renderParams.vertexColor = ELF_FALSE;
		gfxSetColor(&shaderParams->materialParams.diffuseColor, 1.0f, 1.0f, 1.0f, 0.6f);
		gfxSetShaderParams(shaderParams);

		elfDrawString(button->font, button->text, button->pos.x+(button->width-elfGetStringWidth(button->font, button->text))/2,
			button->pos.y+(button->height-elfGetStringHeight(button->font, button->text))/2-button->font->offsetY/2, shaderParams);
	}
	else
	{
		shaderParams->textureParams[0].texture = button->off->texture;

		if(button->state == ELF_OVER)
		{
			if(button->over) shaderParams->textureParams[0].texture = button->over->texture;
		}
		else if(button->state == ELF_ON)
		{
			if(button->on) shaderParams->textureParams[0].texture = button->on->texture;
		}

		if(shaderParams->textureParams[0].texture)
		{
			gfxSetShaderParams(shaderParams);
			gfxDrawTextured2dQuad((float)button->pos.x, (float)button->pos.y, (float)button->width, (float)button->height);
			shaderParams->textureParams[0].texture = NULL;
		}
	}
}

void elfRecalcButton(elfButton* button)
{
	if(button->off)
	{
		button->width = elfGetTextureWidth(button->off);
		button->height = elfGetTextureHeight(button->off);
	}
}

ELF_API unsigned char ELF_APIENTRY elfGetButtonState(elfButton* button)
{
	return button->state;
}

ELF_API const char* ELF_APIENTRY elfGetButtonText(elfButton* button)
{
	return button->text;
}

ELF_API elfFont* ELF_APIENTRY elfGetButtonFont(elfButton* button)
{
	return button->font;
}

ELF_API elfVec2i ELF_APIENTRY elfGetButtonSize(elfButton* button)
{
	elfVec2i size;

	size.x = button->width;
	size.y = button->height;

	return size;
}

ELF_API elfTexture* ELF_APIENTRY elfGetButtonOffTexture(elfButton* button)
{
	return button->off;
}

ELF_API elfTexture* ELF_APIENTRY elfGetButtonOverTexture(elfButton* button)
{
	return button->over;
}

ELF_API elfTexture* ELF_APIENTRY elfGetButtonOnTexture(elfButton* button)
{
	return button->on;
}

ELF_API void ELF_APIENTRY elfSetButtonText(elfButton* button, const char* text)
{
	if(button->text) elfDestroyString(button->text);
	button->text = elfCreateString(text);
	elfRecalcGuiObject((elfGuiObject*)button);
}

ELF_API void ELF_APIENTRY elfSetButtonFont(elfButton* button, elfFont* font)
{
	if(button->font) elfDecRef((elfObject*)button->font);
	button->font = font;
	if(button->font) elfIncRef((elfObject*)button->font);
	elfRecalcGuiObject((elfGuiObject*)button);
}

ELF_API void ELF_APIENTRY elfSetButtonSize(elfButton* button, int width, int height)
{
	button->width = width;
	button->height = height;
	if(button->width < 1) button->width = 1;
	if(button->height < 1) button->height = 1;
	elfRecalcGuiObject((elfGuiObject*)button);
}

ELF_API void ELF_APIENTRY elfSetButtonOffTexture(elfButton* button, elfTexture* off)
{
	if(button->off) elfDecRef((elfObject*)button->off);
	button->off = off;
	if(button->off) elfIncRef((elfObject*)button->off);
	elfRecalcGuiObject((elfGuiObject*)button);
}

ELF_API void ELF_APIENTRY elfSetButtonOverTexture(elfButton* button, elfTexture* over)
{
	if(button->over) elfDecRef((elfObject*)button->over);
	button->over = over;
	if(button->over) elfIncRef((elfObject*)button->over);
}

ELF_API void ELF_APIENTRY elfSetButtonOnTexture(elfButton* button, elfTexture* on)
{
	if(button->on) elfDecRef((elfObject*)button->on);
	button->on = on;
	if(button->on) elfIncRef((elfObject*)button->on);
}

ELF_API elfPicture* ELF_APIENTRY elfCreatePicture(elfGuiObject* parent, const char* name, int x, int y, const char *path)
{
	elfPicture* picture;
	elfTexture* texture;

	picture = (elfPicture*)malloc(sizeof(elfPicture));
	memset(picture, 0x0, sizeof(elfPicture));
	picture->objType = ELF_PICTURE;
	picture->objDestr = elfDestroyPicture;

	picture->color.r = picture->color.g = picture->color.b = picture->color.a = 1.0f;
	picture->scale.x = picture->scale.y = 1.0f;
	picture->visible = ELF_TRUE;

	if(name) picture->name = elfCreateString(name);

	elfSetGuiObjectPosition((elfGuiObject*)picture, x, y);
	texture = elfGetOrLoadResourcesTexture(path, NULL);
	if(texture) elfSetPictureTexture(picture, texture);
	elfAddGuiObject(parent, (elfGuiObject*)picture);

	elfIncObj(ELF_PICTURE);

	return picture;
}

void elfDestroyPicture(void* data)
{
	elfPicture* picture = (elfPicture*)data;

	if(picture->name) elfDestroyString(picture->name);
	if(picture->texture) elfDecRef((elfObject*)picture->texture);

	free(picture);

	elfDecObj(ELF_PICTURE);
}

void elfDrawPicture(elfPicture* picture, gfxShaderParams* shaderParams)
{
	if(!picture->visible || !picture->texture) return;

	gfxSetColor(&shaderParams->materialParams.diffuseColor, picture->color.r,
		picture->color.g, picture->color.b, picture->color.a);

	shaderParams->textureParams[0].texture = picture->texture->texture;
	gfxSetShaderParams(shaderParams);
	gfxDrawTextured2dQuad((float)picture->pos.x, (float)picture->pos.y, (float)picture->width, (float)picture->height);
	shaderParams->textureParams[0].texture = NULL;
}

void elfRecalcPicture(elfPicture* picture)
{
	if(picture->texture)
	{
		picture->width = elfGetTextureWidth(picture->texture)*picture->scale.x;
		picture->height = elfGetTextureHeight(picture->texture)*picture->scale.y;
	}
	else
	{
		picture->height = 0;
		picture->width = 0;
	}
}

ELF_API elfTexture* ELF_APIENTRY elfGetPictureTexture(elfPicture* picture)
{
	return picture->texture;
}

ELF_API elfVec2f ELF_APIENTRY elfGetPictureScale(elfPicture* picture)
{
	return picture->scale;
}

ELF_API void ELF_APIENTRY elfSetPictureTexture(elfPicture* picture, elfTexture* texture)
{
	if(picture->texture) elfDecRef((elfObject*)picture->texture);
	picture->texture = texture;
	if(picture->texture) elfIncRef((elfObject*)picture->texture);
	elfRecalcGuiObject((elfGuiObject*)picture);
}

ELF_API void ELF_APIENTRY elfSetPictureScale(elfPicture* picture, float x, float y)
{
	picture->scale.x = x;
	picture->scale.y = y;
	elfRecalcGuiObject((elfGuiObject*)picture);
}

ELF_API elfTextField* ELF_APIENTRY elfCreateTextField(elfGuiObject* parent, const char* name, int x, int y, int width, const char* text)
{
	elfTextField* textField;

	textField = (elfTextField*)malloc(sizeof(elfTextField));
	memset(textField, 0x0, sizeof(elfTextField));
	textField->objType = ELF_TEXT_FIELD;
	textField->objDestr = elfDestroyTextField;

	textField->color.r = textField->color.g = textField->color.b = 1.0f; textField->color.a = 0.6f;
	textField->textColor.r = textField->textColor.g = textField->textColor.b = textField->textColor.a = 1.0f;
	textField->visible = ELF_TRUE;
	textField->text = elfCreateString("");

	if(name) textField->name = elfCreateString(name);

	elfSetGuiObjectPosition((elfGuiObject*)textField, x, y);
	elfSetTextFieldFont(textField, eng->guiFont);	
	elfSetTextFieldWidth(textField, width);
	elfSetTextFieldOffset(textField, 2, 2);
	elfAddGuiObject(parent, (elfGuiObject*)textField);

	elfIncObj(ELF_TEXT_FIELD);

	return textField;
}

void elfDestroyTextField(void* data)
{
	elfTextField* textField = (elfTextField*)data;

	if(textField->name) elfDestroyString(textField->name);

	if(textField->texture) elfDecRef((elfObject*)textField->texture);
	if(textField->font) elfDecRef((elfObject*)textField->font);
	if(textField->text) elfDestroyString(textField->text);
	if(textField->script) elfDecRef((elfObject*)textField->script);

	free(textField);

	elfDecObj(ELF_TEXT_FIELD);
}

void elfDrawTextField(elfTextField* textField, elfArea* area, gfxShaderParams* shaderParams)
{
	char* str;
	int x, y, width, height;

	if(!textField->visible) return;

	x = textField->pos.x;
	y = textField->pos.y;
	width = textField->width;
	height = textField->height;
	if(textField->parent)
	{
		if(x < area->pos.x)
		{
			width -= area->pos.x-x;
			x = area->pos.x;
		}
		if(y < area->pos.y)
		{
			height -= area->pos.y-y;
			y = area->pos.y;
		}
		if(x+width > area->pos.x+area->size.x)
			width -= (x+width)-(area->pos.x+area->size.x);
		if(y+height > area->pos.y+area->size.y)
			height -= (y+height)-(area->pos.y+area->size.y);
	}

	if(!textField->texture)
	{
		elfColor col1, col2;

		shaderParams->renderParams.vertexColor = GFX_TRUE;
		gfxSetColor(&shaderParams->materialParams.diffuseColor, 1.0f, 1.0f, 1.0f, 1.0f);
		gfxSetShaderParams(shaderParams);

		col1.r = col1.g = col1.b = 0.15f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.35f; col2.a = 1.0f;
		elfDrawHorGradient(textField->pos.x, textField->pos.y, textField->width, textField->height, col1, col2);

		col1.r = col1.g = col1.b = 0.25f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.4f; col2.a = 1.0f;
		elfDrawHorGradientBorder(textField->pos.x, textField->pos.y, textField->width, textField->height, col1, col2);

		shaderParams->renderParams.vertexColor = GFX_FALSE;
	}
	else
	{
		gfxSetColor(&shaderParams->materialParams.diffuseColor, textField->color.r,
			textField->color.g, textField->color.b, textField->color.a);
		shaderParams->textureParams[0].texture = textField->texture->texture;

		if(shaderParams->textureParams[0].texture)
		{
			gfxSetShaderParams(shaderParams);
			gfxDrawTextured2dQuad((float)textField->pos.x, (float)textField->pos.y, (float)textField->width, (float)textField->height);
			shaderParams->textureParams[0].texture = NULL;
		}
	}

	if(textField->font && textField->text && strlen(textField->text) > 0)
	{
		gfxSetViewport(x, y, width, height);
		gfxGetOrthographicProjectionMatrix((float)x, (float)x+width, (float)y, (float)y+height,
			-1.0f, 1.0f, shaderParams->projectionMatrix);

		gfxSetColor(&shaderParams->materialParams.diffuseColor, textField->textColor.r, textField->textColor.g,
			textField->textColor.b, textField->textColor.a*textField->color.a);

		str = elfSubString(textField->text, textField->drawPos,
			strlen(textField->text)-textField->drawPos);
		elfDrawString(textField->font, str, textField->pos.x+textField->offsetX, textField->pos.y+textField->offsetY-textField->font->offsetY/2, shaderParams);
		elfDestroyString(str);

		shaderParams->textureParams[0].texture = NULL;
	}

	if(textField->text && textField->root && textField->root->activeTextField == textField)
	{
		gfxSetShaderParams(shaderParams);

		str = elfSubString(textField->text, textField->drawPos,
			textField->cursorPos-textField->drawPos);
		gfxDraw2dQuad(textField->pos.x+textField->offsetX+elfGetStringWidth(textField->font, str),
			textField->pos.y+textField->offsetY, 1, textField->height-textField->offsetY*2);
		elfDestroyString(str);
	}
}

void elfRecalcTextField(elfTextField* textField)
{
	if(textField->texture)
	{
		textField->width = elfGetTextureWidth(textField->texture);
		textField->height = elfGetTextureHeight(textField->texture);
	}
}

ELF_API elfTexture* ELF_APIENTRY elfGetTextFieldTexture(elfTextField* textField)
{
	return textField->texture;
}

ELF_API elfFont* ELF_APIENTRY elfGetTextFieldFont(elfTextField* textField)
{
	return textField->font;
}

ELF_API elfColor ELF_APIENTRY elfGetTextFieldTextColor(elfTextField* textField)
{
	return textField->textColor;
}

ELF_API elfVec2i ELF_APIENTRY elfGetTextFieldOffset(elfTextField* textField)
{
	elfVec2i offset;

	offset.x = textField->offsetX;
	offset.y = textField->offsetY;

	return offset;
}

ELF_API const char* ELF_APIENTRY elfGetTextFieldText(elfTextField* textField)
{
	return textField->text;
}

ELF_API void ELF_APIENTRY elfSetTextFieldFont(elfTextField* textField, elfFont* font)
{
	if(textField->font) elfDecRef((elfObject*)textField->font);
	textField->font = font;
	if(textField->font)
	{
		elfIncRef((elfObject*)textField->font);
		textField->height = textField->font->size+textField->font->size/2;
	}
	else textField->height = 0;
	elfRecalcGuiObject((elfGuiObject*)textField);
}

ELF_API void ELF_APIENTRY elfSetTextFieldWidth(elfTextField* textField, int width)
{
	textField->width = width;
	elfRecalcGuiObject((elfGuiObject*)textField);
}

ELF_API void ELF_APIENTRY elfSetTextFieldTexture(elfTextField* textField, elfTexture* texture)
{
	if(textField->texture) elfDecRef((elfObject*)textField->texture);
	textField->texture = texture;
	if(textField->texture) elfIncRef((elfObject*)textField->texture);
	elfRecalcGuiObject((elfGuiObject*)textField);
}

ELF_API void ELF_APIENTRY elfSetTextFieldTextColor(elfTextField* textField, float r, float g, float b, float a)
{
	textField->textColor.r = r;
	textField->textColor.g = g;
	textField->textColor.b = b;
	textField->textColor.a = a;
}

ELF_API void ELF_APIENTRY elfSetTextFieldOffset(elfTextField* textField, int offsetX, int offsetY)
{
	textField->offsetX = offsetX;
	textField->offsetY = offsetY;
}

void elfMoveTextFieldCursorLeft(elfTextField* textField)
{
	if(textField->cursorPos == 0) return;

	textField->cursorPos--;

	if(textField->cursorPos == textField->drawPos &&
		textField->drawPos > 0)
	{
		textField->drawPos--;
	}
}

void elfMoveTextFieldCursorRight(elfTextField* textField)
{
	char* str;

	if(textField->cursorPos >= (int)strlen(textField->text)) return;

	textField->cursorPos++;

	if(!textField->font) return;

	str = elfSubString(textField->text, textField->drawPos,
		textField->cursorPos-textField->drawPos);
	if(elfGetStringWidth(textField->font, str)+2 > textField->width-textField->offsetX*2)
	{
		if(textField->drawPos+5 > textField->cursorPos)
			textField->drawPos += textField->cursorPos-1;
		else textField->drawPos += 5;
	}

	elfDestroyString(str);
}

ELF_API void ELF_APIENTRY elfSetTextFieldCursorPosition(elfTextField* textField, int idx)
{
	if(idx < 0) return;
	if(idx > (int)strlen(textField->text)) idx = strlen(textField->text);

	textField->cursorPos = 0;
	textField->drawPos = 0;

	while(textField->cursorPos < idx)
		elfMoveTextFieldCursorRight(textField);
}

ELF_API void ELF_APIENTRY elfSetTextFieldText(elfTextField* textField, const char* text)
{
	if(textField->text) elfDestroyString(textField->text);
	textField->text = elfCreateString(text);
	textField->cursorPos = 0;
	textField->drawPos = 0;

	while(textField->cursorPos < (int)strlen(textField->text))
		elfMoveTextFieldCursorRight(textField);
}

ELF_API elfSlider* ELF_APIENTRY elfCreateSlider(elfGuiObject* parent, const char* name, int x, int y, int width, int height, float value)
{
	elfSlider* slider;

	slider = (elfSlider*)malloc(sizeof(elfSlider));
	memset(slider, 0x0, sizeof(elfSlider));
	slider->objType = ELF_SLIDER;
	slider->objDestr = elfDestroySlider;

	slider->color.r = slider->color.g = slider->color.b = slider->color.a = 1.0f; 
	slider->visible = ELF_TRUE;
	slider->value = 1.0f;

	if(name) slider->name = elfCreateString(name);

	elfSetGuiObjectPosition((elfGuiObject*)slider, x, y);
	elfSetSliderSize(slider, width, height);
	elfSetSliderValue(slider, value);
	elfAddGuiObject(parent, (elfGuiObject*)slider);

	elfIncObj(ELF_SLIDER);

	return slider;
}

void elfDestroySlider(void* data)
{
	elfSlider* slider = (elfSlider*)data;

	if(slider->name) elfDestroyString(slider->name);

	if(slider->background) elfDecRef((elfObject*)slider->background);
	if(slider->slider) elfDecRef((elfObject*)slider->slider);

	if(slider->script) elfDecRef((elfObject*)slider->script);

	free(slider);

	elfDecObj(ELF_SLIDER);
}

void elfDrawSlider(elfSlider* slider, gfxShaderParams* shaderParams)
{
	if(!slider->visible) return;

	if(!slider->background)
	{
		elfColor col1, col2;

		shaderParams->renderParams.vertexColor = GFX_TRUE;
		gfxSetColor(&shaderParams->materialParams.diffuseColor, 1.0, 1.0, 1.0, 1.0);
		gfxSetShaderParams(shaderParams);

		if(slider->width > slider->height)
		{
			col1.r = col1.g = col1.b = 0.40f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.25f; col2.a = 1.0f;
			elfDrawHorGradient(slider->pos.x, slider->pos.y+2, slider->width, 2, col1, col2);
			col1.r = col1.g = col1.b = 0.20f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.10f; col2.a = 1.0f;
			elfDrawHorGradient(slider->pos.x, slider->pos.y, slider->width, 2, col1, col2);

			col1.r = col1.g = col1.b = 0.60f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.45f; col2.a = 1.0f;
			elfDrawHorGradient(slider->pos.x+slider->width*slider->value-4, slider->pos.y+2, 8, 4, col1, col2);
			col1.r = col1.g = col1.b = 0.40f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.30f; col2.a = 1.0f;
			elfDrawHorGradient(slider->pos.x+slider->width*slider->value-4, slider->pos.y-2, 8, 4, col1, col2);
		}
		else	
		{
			col1.r = col1.g = col1.b = 0.40f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.25f; col2.a = 1.0f;
			elfDrawHorGradient(slider->pos.x, slider->pos.y+slider->height/2, slider->width, slider->height/2, col1, col2);
			col1.r = col1.g = col1.b = 0.20f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.10f; col2.a = 1.0f;
			elfDrawHorGradient(slider->pos.x, slider->pos.y, slider->width, slider->height/2, col1, col2);

			col1.r = col1.g = col1.b = 0.60f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.45f; col2.a = 1.0f;
			elfDrawHorGradient(slider->pos.x-2, slider->pos.y+slider->height*slider->value, 8, 4, col1, col2);
			col1.r = col1.g = col1.b = 0.40f; col1.a = 1.0f; col2.r = col2.g = col2.b = 0.30f; col2.a = 1.0f;
			elfDrawHorGradient(slider->pos.x-2, slider->pos.y+slider->height*slider->value-4, 8, 4, col1, col2);
		}

		shaderParams->renderParams.vertexColor = GFX_FALSE;
	}
	else
	{
		gfxSetColor(&shaderParams->materialParams.diffuseColor, slider->color.r, slider->color.g, slider->color.b, slider->color.a);
		shaderParams->textureParams[0].texture = slider->background->texture;
		if(shaderParams->textureParams[0].texture)
		{
			gfxSetShaderParams(shaderParams);
			gfxDrawTextured2dQuad((float)slider->pos.x, (float)slider->pos.y, (float)slider->width, (float)slider->height);
			shaderParams->textureParams[0].texture = NULL;
		}

		if(slider->slider)
		{
			gfxSetColor(&shaderParams->materialParams.diffuseColor, slider->color.r, slider->color.g, slider->color.b, slider->color.a);
			shaderParams->textureParams[0].texture = slider->slider->texture;
			gfxSetShaderParams(shaderParams);
			if(slider->width > slider->height)
			{
				gfxDrawTextured2dQuadRegion((float)slider->pos.x, (float)slider->pos.y, (float)slider->width*slider->value, (float)slider->height, 0.0f, 0.0f, slider->value, 1.0f);
			}
			else
			{
				gfxDrawTextured2dQuadRegion((float)slider->pos.x, (float)slider->pos.y, (float)slider->width, (float)slider->height*slider->value, 0.0f, 0.0f, 1.0f, slider->value);	
			}
			shaderParams->textureParams[0].texture = NULL;
		}
	}
}

ELF_API elfTexture* ELF_APIENTRY elfGetSliderBackgroundTexture(elfSlider* slider)
{
	return slider->background;
}

ELF_API elfTexture* ELF_APIENTRY elfGetSliderSliderTexture(elfSlider* slider)
{
	return slider->slider;
}

ELF_API float ELF_APIENTRY elfGetSliderValue(elfSlider* slider)
{
	return slider->value;
}

void elfRecalcSlider(elfSlider* slider)
{
	if(slider->background)
	{
		slider->width = elfGetTextureWidth(slider->background);
		slider->height = elfGetTextureHeight(slider->background);
	}
}

ELF_API void ELF_APIENTRY elfSetSliderSize(elfSlider* slider, int width, int height)
{
	if(width > height)
	{
		slider->width = width;
		slider->height = 4;
	}
	else
	{
		slider->height = height;
		slider->width = 4;
	}
	elfRecalcGuiObject((elfGuiObject*)slider);
}

ELF_API void ELF_APIENTRY elfSetSliderBackgroundTexture(elfSlider* slider, elfTexture* background)
{
	if(slider->background) elfDecRef((elfObject*)slider->background);
	slider->background = background;
	if(slider->background) elfIncRef((elfObject*)slider->background);
	elfRecalcGuiObject((elfGuiObject*)slider);
}

ELF_API void ELF_APIENTRY elfSetSliderSliderTexture(elfSlider* slider, elfTexture* sliderTexture)
{
	if(slider->slider) elfDecRef((elfObject*)slider->slider);
	slider->slider = sliderTexture;
	if(slider->slider) elfIncRef((elfObject*)slider->slider);
}

ELF_API void ELF_APIENTRY elfSetSliderValue(elfSlider* slider, float value)
{
	slider->value = value;
	if(slider->value < 0.0f) slider->value = 0.0f;
	if(slider->value > 1.0f) slider->value = 1.0f;
}

ELF_API elfScreen* ELF_APIENTRY elfCreateScreen(const char* name)
{
	elfScreen* screen;

	screen = (elfScreen*)malloc(sizeof(elfScreen));
	memset(screen, 0x0, sizeof(elfScreen));
	screen->objType = ELF_SCREEN;
	screen->objDestr = elfDestroyScreen;

	screen->color.r = screen->color.g = screen->color.b = screen->color.a = 1.0f;
	screen->visible = ELF_TRUE;

	screen->children = elfCreateList();
	screen->screens = elfCreateList();

	elfIncRef((elfObject*)screen->children);
	elfIncRef((elfObject*)screen->screens);

	if(name) screen->name = elfCreateString(name);

	elfIncObj(ELF_SCREEN);

	return screen;
}

void elfDestroyScreen(void* data)
{
	elfScreen* screen = (elfScreen*)data;

	if(screen->name) elfDestroyString(screen->name);
	if(screen->texture) elfDecRef((elfObject*)screen->texture);

	elfDecRef((elfObject*)screen->children);
	elfDecRef((elfObject*)screen->screens);

	free(screen);

	elfDecObj(ELF_SCREEN);
}

void elfDrawScreen(elfScreen* screen, elfArea* area, gfxShaderParams* shaderParams)
{
	elfGuiObject* object;
	int x, y, width, height;

	if(!screen->visible || !screen->texture) return;

	x = screen->pos.x;
	y = screen->pos.y;
	width = screen->width;
	height = screen->height;
	if(screen->parent)
	{
		if(x < area->pos.x)
		{
			width -= area->pos.x-x;
			x = area->pos.x;
		}
		if(y < area->pos.y)
		{
			height -= area->pos.y-y;
			y = area->pos.y;
		}
		if(x+width > area->pos.x+area->size.x)
			width -= (x+width)-(area->pos.x+area->size.x);
		if(y+height > area->pos.y+area->size.y)
			height -= (y+height)-(area->pos.y+area->size.y);
	}

	gfxSetColor(&shaderParams->materialParams.diffuseColor, screen->color.r, screen->color.g, screen->color.b, screen->color.a);

	shaderParams->textureParams[0].texture = screen->texture->texture;
	gfxSetShaderParams(shaderParams);
	gfxDrawTextured2dQuad((float)screen->pos.x, (float)screen->pos.y, (float)screen->width, (float)screen->height);
	shaderParams->textureParams[0].texture = NULL;

	gfxSetViewport(x, y, width, height);
	gfxGetOrthographicProjectionMatrix((float)x, (float)x+width, (float)y, (float)y+height,
		-1.0f, 1.0f, shaderParams->projectionMatrix);

	for(object = (elfGuiObject*)elfBeginList(screen->children); object;
		object = (elfGuiObject*)elfGetListNext(screen->children))
	{
		if(object->objType == ELF_LABEL) elfDrawLabel((elfLabel*)object, shaderParams);
		else if(object->objType == ELF_BUTTON) elfDrawButton((elfButton*)object, shaderParams);
		else if(object->objType == ELF_PICTURE) elfDrawPicture((elfPicture*)object, shaderParams);
		else if(object->objType == ELF_TEXT_FIELD)
		{
			elfDrawTextField((elfTextField*)object, area, shaderParams);
			gfxSetViewport(x, y, width, height);
			gfxGetOrthographicProjectionMatrix((float)x, (float)x+width, (float)y, (float)y+height,
				-1.0f, 1.0f, shaderParams->projectionMatrix);
		}
		else if(object->objType == ELF_TEXT_LIST)
		{
			elfDrawTextList((elfTextList*)object, area, shaderParams);
			gfxSetViewport(x, y, width, height);
			gfxGetOrthographicProjectionMatrix((float)x, (float)x+width, (float)y, (float)y+height,
				-1.0f, 1.0f, shaderParams->projectionMatrix);
		}
		else if(object->objType == ELF_SLIDER) elfDrawSlider((elfSlider*)object, shaderParams);
		else if(object->objType == ELF_CHECK_BOX) elfDrawCheckBox((elfCheckBox*)object, shaderParams);
	}

	for(object = (elfGuiObject*)elfBeginList(screen->screens); object;
		object = (elfGuiObject*)elfGetListNext(screen->screens))
	{
		area->pos.x = x; area->pos.y = y; area->size.x = width; area->size.y = height;
		elfDrawScreen((elfScreen*)object, area, shaderParams);
		gfxSetViewport(x, y, width, height);
		gfxGetOrthographicProjectionMatrix((float)x, (float)x+width, (float)y, (float)y+height,
			-1.0f, 1.0f, shaderParams->projectionMatrix);
	}
}

ELF_API elfTexture* ELF_APIENTRY elfGetScreenTexture(elfScreen* screen)
{
	return screen->texture;
}

void elfRecalcScreen(elfScreen* screen)
{
	if(screen->texture)
	{
		screen->width = elfGetTextureWidth(screen->texture);
		screen->height = elfGetTextureHeight(screen->texture);
	}
	else
	{
		screen->height = 0;
		screen->width = 0;
	}
}

ELF_API void ELF_APIENTRY elfSetScreenTexture(elfScreen* screen, elfTexture* texture)
{
	if(screen->texture) elfDecRef((elfObject*)screen->texture);
	screen->texture = texture;
	if(screen->texture) elfIncRef((elfObject*)screen->texture);
	elfRecalcGuiObject((elfGuiObject*)screen);
}

ELF_API void ELF_APIENTRY elfSetScreenToTop(elfScreen* screen)
{
	if(!screen->parent) return;

	elfIncRef((elfObject*)screen);
	elfRemoveListObject(screen->parent->screens, (elfObject*)screen);
	elfAppendListObject(screen->parent->screens, (elfObject*)screen);
	elfDecRef((elfObject*)screen);
}

ELF_API void ELF_APIENTRY elfForceScreenFocus(elfScreen* screen)
{
	elfButton* button;

	if(!screen->root) return;

	if(screen->root->target && screen->root->target->objType == ELF_BUTTON)
	{
		button = (elfButton*)screen->root->target;
		button->state = ELF_OFF;
	}

	screen->root->trace = NULL;
	screen->root->target = NULL;
	screen->root->activeTextField = NULL;

	screen->root->focusScreen = screen;
}

ELF_API void ELF_APIENTRY elfReleaseFocusFromScreen(elfScreen* screen)
{
	if(!screen->root) return;

	screen->root->focusScreen = NULL;
}

ELF_API elfTextList* ELF_APIENTRY elfCreateTextList(const char* name)
{
	elfTextList* textList;

	textList = (elfTextList*)malloc(sizeof(elfTextList));
	memset(textList, 0x0, sizeof(elfTextList));
	textList->objType = ELF_TEXT_LIST;
	textList->objDestr = elfDestroyTextList;

	textList->color.r = textList->color.g = textList->color.b = textList->color.a = 1.0f;
	textList->selectionColor.r = textList->selectionColor.g = textList->selectionColor.b = textList->selectionColor.a = 0.5f;
	textList->lightColor.r = textList->lightColor.g = textList->lightColor.b = 0.0f; textList->lightColor.a = 0.25f;
	textList->darkColor.r = textList->darkColor.g = textList->darkColor.b = 0.0f; textList->darkColor.a = 0.125f;
	textList->visible = ELF_TRUE;
	textList->rows = 16;
	textList->listWidth = 256;
	textList->selection = -1;

	textList->items = elfCreateList();
	elfIncRef((elfObject*)textList->items);

	if(name) textList->name = elfCreateString(name);

	elfIncObj(ELF_TEXT_LIST);

	return textList;
}

void elfDestroyTextList(void* data)
{
	elfTextList* textList = (elfTextList*)data;

	if(textList->name) elfDestroyString(textList->name);
	if(textList->font) elfDecRef((elfObject*)textList->font);

	elfDecRef((elfObject*)textList->items);

	free(textList);

	elfDecObj(ELF_TEXT_LIST);
}

void elfDrawTextList(elfTextList* textList, elfArea* area, gfxShaderParams* shaderParams)
{
	int x, y, width, height;
	int offset;
	int i;
	unsigned char light;
	elfString* strObj;

	if(!textList->visible || !textList->font || elfGetListLength(textList->items) < 1) return;

	x = textList->pos.x;
	y = textList->pos.y;
	width = textList->width;
	height = textList->height;
	if(textList->parent)
	{
		if(x < area->pos.x)
		{
			width -= area->pos.x-x;
			x = area->pos.x;
		}
		if(y < area->pos.y)
		{
			height -= area->pos.y-y;
			y = area->pos.y;
		}
		if(x+width > area->pos.x+area->size.x)
			width -= (x+width)-(area->pos.x+area->size.x);
		if(y+height > area->pos.y+area->size.y)
			height -= (y+height)-(area->pos.y+area->size.y);
	}

	gfxSetViewport(x, y, width, height);
	gfxGetOrthographicProjectionMatrix((float)x, (float)x+width, (float)y, (float)y+height,
		-1.0f, 1.0f, shaderParams->projectionMatrix);
	gfxSetColor(&shaderParams->materialParams.diffuseColor, textList->color.r,
		textList->color.g, textList->color.b, textList->color.a);

	light = ELF_TRUE;
	offset = textList->font->size+textList->font->offsetY;
	for(i = 0, strObj = (elfString*)elfBeginList(textList->items); strObj;
		strObj = (elfString*)elfGetListNext(textList->items), i++)
	{
		if(i < textList->offset) continue;
		if(i-textList->offset > textList->rows-1) break;

		if(i == textList->selection)
		{
			shaderParams->textureParams[0].texture = NULL;
			gfxSetColor(&shaderParams->materialParams.diffuseColor, textList->selectionColor.r,
				textList->selectionColor.g, textList->selectionColor.b, textList->selectionColor.a);
			gfxSetShaderParams(shaderParams);	
			gfxDraw2dQuad((float)textList->pos.x, (float)textList->pos.y+textList->height-offset,
				(float)textList->listWidth, (float)textList->font->size+textList->font->offsetY);
		}
		else
		{
			shaderParams->textureParams[0].texture = NULL;
			if(light) gfxSetColor(&shaderParams->materialParams.diffuseColor, textList->lightColor.r,
				textList->lightColor.g, textList->lightColor.b, textList->lightColor.a);
			else gfxSetColor(&shaderParams->materialParams.diffuseColor, textList->darkColor.r,
				textList->darkColor.g, textList->darkColor.b, textList->darkColor.a);
			gfxSetShaderParams(shaderParams);	
			gfxDraw2dQuad((float)textList->pos.x, (float)textList->pos.y+textList->height-offset,
				(float)textList->listWidth, (float)textList->font->size+textList->font->offsetY);
		}

		light = !light;

		gfxSetColor(&shaderParams->materialParams.diffuseColor, textList->color.r,
			textList->color.g, textList->color.b, textList->color.a);
		elfDrawString(textList->font, strObj->str, textList->pos.x, textList->pos.y+textList->height-offset, shaderParams);

		offset += textList->font->size+textList->font->offsetY;
	}

	shaderParams->textureParams[0].texture = NULL;
}

ELF_API elfFont* ELF_APIENTRY elfGetTextListFont(elfTextList* textList)
{
	return textList->font;
}

ELF_API elfColor ELF_APIENTRY elfGetTextListSelectionColor(elfTextList* textList)
{
	return textList->selectionColor;
}

ELF_API elfColor ELF_APIENTRY elfGetTextListLightColor(elfTextList* textList)
{
	return textList->lightColor;
}

ELF_API elfColor ELF_APIENTRY elfGetTextListDarkColor(elfTextList* textList)
{
	return textList->darkColor;
}

ELF_API int ELF_APIENTRY elfGetTextListRowCount(elfTextList* textList)
{
	return textList->rows;
}

ELF_API int ELF_APIENTRY elfGetTextListItemCount(elfTextList* textList)
{
	return elfGetListLength(textList->items);
}

ELF_API int ELF_APIENTRY elfGetTextListSelectionIndex(elfTextList* textList)
{
	return textList->selection;
}

ELF_API int ELF_APIENTRY elfGetTextListOffset(elfTextList* textList)
{
	return textList->offset;
}

ELF_API const char* ELF_APIENTRY elfGetTextListItem(elfTextList* textList, int idx)
{
	int i;
	elfString* strObj;

	if(idx < 0 || idx > elfGetListLength(textList->items)-1) return "";

	for(i = 0, strObj = (elfString*)elfBeginList(textList->items); strObj;
		strObj = (elfString*)elfGetListNext(textList->items), i++)
	{
		if(idx == i) return strObj->str;
	}

	return "";
}

ELF_API const char* ELF_APIENTRY elfGetTextListSelectedItem(elfTextList* textList)
{
	int i;
	elfString* strObj;

	if(textList->selection < 0 || textList->selection > elfGetListLength(textList->items)-1) return "";

	for(i = 0, strObj = (elfString*)elfBeginList(textList->items); strObj;
		strObj = (elfString*)elfGetListNext(textList->items), i++)
	{
		if(textList->selection == i) return strObj->str;
	}

	return "";
}

void elfRecalcTextList(elfTextList* textList)
{
	if(textList->font)
	{
		textList->height = (textList->font->size+textList->font->offsetY)*textList->rows;
		textList->width = textList->listWidth;
	}
	else
	{
		textList->height = 0;
		textList->width = 0;
	}
}

ELF_API void ELF_APIENTRY elfSetTextListFont(elfTextList* textList, elfFont* font)
{
	if(textList->font) elfDecRef((elfObject*)textList->font);
	textList->font = font;
	if(textList->font) elfIncRef((elfObject*)textList->font);
	elfRecalcGuiObject((elfGuiObject*)textList);
}

ELF_API void ELF_APIENTRY elfSetTextListSelectionColor(elfTextList* textList, float r, float g, float b, float a)
{
	textList->selectionColor.r = r;
	textList->selectionColor.g = g;
	textList->selectionColor.b = b;
	textList->selectionColor.a = a;
}

ELF_API void ELF_APIENTRY elfSetTextListLightColor(elfTextList* textList, float r, float g, float b, float a)
{
	textList->lightColor.r = r;
	textList->lightColor.g = g;
	textList->lightColor.b = b;
	textList->lightColor.a = a;
}

ELF_API void ELF_APIENTRY elfSetTextListDarkColor(elfTextList* textList, float r, float g, float b, float a)
{
	textList->darkColor.r = r;
	textList->darkColor.g = g;
	textList->darkColor.b = b;
	textList->darkColor.a = a;
}

ELF_API void ELF_APIENTRY elfSetTextListSize(elfTextList* textList, int rows, int width)
{
	textList->rows = rows;
	textList->listWidth = width;
	if(textList->rows < 1) textList->rows = 1;
	if(textList->listWidth < 1) textList->width = 1;
	elfRecalcGuiObject((elfGuiObject*)textList);
}

ELF_API void ELF_APIENTRY elfAddTextListItem(elfTextList* textList, const char* text)
{
	elfString* strObj;

	if(!text) return;

	strObj = elfCreateStringObject();
	strObj->str = elfCreateString(text);

	elfAppendListObject(textList->items, (elfObject*)strObj);
}

ELF_API void ELF_APIENTRY elfSetTextListItem(elfTextList* textList, int idx, const char* text)
{
	elfString* strObj;

	strObj = (elfString*)elfGetListObject(textList->items, idx);
	if(strObj)
	{
		if(strObj->str) elfDestroyString(strObj->str);
		strObj->str = elfCreateString(text);
	}
}

ELF_API unsigned char ELF_APIENTRY elfRemoveTextListItem(elfTextList* textList, int idx)
{
	int i;
	elfString* strObj;

	if(idx < 0 || idx > elfGetListLength(textList->items)-1) return ELF_FALSE;

	for(i = 0, strObj = (elfString*)elfBeginList(textList->items); strObj;
		strObj = (elfString*)elfGetListNext(textList->items), i++)
	{
		if(idx == i)
		{
			if(idx == textList->selection) textList->selection = -1;
			elfRemoveListObject(textList->items, (elfObject*)strObj);
			return ELF_TRUE;
		}
	}

	return ELF_FALSE;
}

ELF_API void ELF_APIENTRY elfRemoveTextListItems(elfTextList* textList)
{
	elfDecRef((elfObject*)textList->items);
	textList->items = elfCreateList();
	elfIncRef((elfObject*)textList->items);
	textList->offset = 0;
	textList->selection = 0;
}

ELF_API void ELF_APIENTRY elfSetTextListOffset(elfTextList* textList, int offset)
{
	textList->offset = offset;
	if(textList->offset < 0) textList->offset = 0;
}

ELF_API void ELF_APIENTRY elfSetTextListSelection(elfTextList* textList, int selection)
{
	textList->selection = selection;
	if(textList->selection < 0) textList->selection = -1;
	if(textList->selection > elfGetListLength(textList->items)-1)
		textList->selection = elfGetListLength(textList->items)-1;
	if(elfGetListLength(textList->items) == 0) textList->selection = -1;
}

ELF_API elfCheckBox* ELF_APIENTRY elfCreateCheckBox(const char* name)
{
	elfCheckBox* checkBox;

	checkBox = (elfCheckBox*)malloc(sizeof(elfCheckBox));
	memset(checkBox, 0x0, sizeof(elfCheckBox));
	checkBox->objType = ELF_CHECK_BOX;
	checkBox->objDestr = elfDestroyCheckBox;

	checkBox->color.r = checkBox->color.g = checkBox->color.b = checkBox->color.a = 1.0f;
	checkBox->visible = ELF_TRUE;

	if(name) checkBox->name = elfCreateString(name);

	elfIncObj(ELF_CHECK_BOX);

	return checkBox;
}

void elfDestroyCheckBox(void* data)
{
	elfCheckBox* checkBox = (elfCheckBox*)data;

	if(checkBox->name) elfDestroyString(checkBox->name);

	if(checkBox->off) elfDecRef((elfObject*)checkBox->off);
	if(checkBox->on) elfDecRef((elfObject*)checkBox->on);

	if(checkBox->script) elfDecRef((elfObject*)checkBox->script);

	free(checkBox);

	elfDecObj(ELF_CHECK_BOX);
}

void elfDrawCheckBox(elfCheckBox* checkBox, gfxShaderParams* shaderParams)
{
	if(!checkBox->visible) return;

	gfxSetColor(&shaderParams->materialParams.diffuseColor, checkBox->color.r,
		checkBox->color.g, checkBox->color.b, checkBox->color.a);

	if(checkBox->state == ELF_OFF)
	{
		if(checkBox->off) shaderParams->textureParams[0].texture = checkBox->off->texture;
	}
	else if(checkBox->state == ELF_ON)
	{
		if(checkBox->on) shaderParams->textureParams[0].texture = checkBox->on->texture;
	}

	if(shaderParams->textureParams[0].texture)
	{
		gfxSetShaderParams(shaderParams);
		gfxDrawTextured2dQuad((float)checkBox->pos.x, (float)checkBox->pos.y, (float)checkBox->width, (float)checkBox->height);
		shaderParams->textureParams[0].texture = NULL;
	}
}

ELF_API unsigned char ELF_APIENTRY elfGetCheckBoxState(elfCheckBox* checkBox)
{
	return checkBox->state;
}

ELF_API elfTexture* ELF_APIENTRY elfGetCheckBoxOffTexture(elfCheckBox* checkBox)
{
	return checkBox->off;
}

ELF_API elfTexture* ELF_APIENTRY elfGetCheckBoxOnTexture(elfCheckBox* checkBox)
{
	return checkBox->on;
}

void elfRecalcCheckBox(elfCheckBox* checkBox)
{
	if(checkBox->off)
	{
		checkBox->width = elfGetTextureWidth(checkBox->off);
		checkBox->height = elfGetTextureHeight(checkBox->off);
	}
	else
	{
		checkBox->height = 0;
		checkBox->width = 0;
	}
}

ELF_API void ELF_APIENTRY elfSetCheckBoxOffTexture(elfCheckBox* checkBox, elfTexture* off)
{
	if(checkBox->off) elfDecRef((elfObject*)checkBox->off);
	checkBox->off = off;
	if(checkBox->off) elfIncRef((elfObject*)checkBox->off);
	elfRecalcGuiObject((elfGuiObject*)checkBox);
}

ELF_API void ELF_APIENTRY elfSetCheckBoxOnTexture(elfCheckBox* checkBox, elfTexture* on)
{
	if(checkBox->on) elfDecRef((elfObject*)checkBox->on);
	checkBox->on = on;
	if(checkBox->on) elfIncRef((elfObject*)checkBox->on);
}

ELF_API void ELF_APIENTRY elfSetCheckBoxState(elfCheckBox* checkBox, unsigned char state)
{
	checkBox->state = !state == ELF_OFF;
}

void elfRecalcGuiObject(elfGuiObject* object)
{
	elfGuiObject* obj;

	if(object->objType == ELF_LABEL) elfRecalcLabel((elfLabel*)object);
	else if(object->objType == ELF_BUTTON) elfRecalcButton((elfButton*)object);
	else if(object->objType == ELF_PICTURE) elfRecalcPicture((elfPicture*)object);
	else if(object->objType == ELF_TEXT_FIELD) elfRecalcTextField((elfTextField*)object);
	else if(object->objType == ELF_SLIDER) elfRecalcSlider((elfSlider*)object);
	else if(object->objType == ELF_SCREEN) elfRecalcScreen((elfScreen*)object);
	else if(object->objType == ELF_TEXT_LIST) elfRecalcTextList((elfTextList*)object);
	else if(object->objType == ELF_CHECK_BOX) elfRecalcCheckBox((elfCheckBox*)object);

	if(object->parent)
	{
		object->pos.x = object->parent->pos.x+object->relPos.x;
		object->pos.y = object->parent->pos.y+object->parent->height-object->relPos.y-object->height;
	}
	else
	{
		object->pos.x = object->relPos.x;
		object->pos.y = elfGetWindowHeight()-object->relPos.y-object->height;
	}

	if(object->children)
	{
		for(obj = (elfGuiObject*)elfBeginList(object->children); obj;
			obj = (elfGuiObject*)elfGetListNext(object->children))
		{
			elfRecalcGuiObject(obj);
		}
	}

	if(object->screens)
	{
		for(obj = (elfGuiObject*)elfBeginList(object->screens); obj;
			obj = (elfGuiObject*)elfGetListNext(object->screens))
		{
			elfRecalcGuiObject(obj);
		}
	}
}

void elfClearGuiObjectRoot(elfGuiObject* object)
{
	elfGuiObject* cobject;

	if(object->children)
	{
		for(cobject = (elfGuiObject*)elfBeginList(object->children); cobject;
			cobject = (elfGuiObject*)elfGetListNext(object->children))
		{
			elfClearGuiObjectRoot(cobject);
		}
	}

	object->root = NULL;
}

void elfSetGuiObjectRoot(elfGuiObject* object, elfGui* root)
{
	elfGuiObject* cobject;

	if(object->children)
	{
		for(cobject = (elfGuiObject*)elfBeginList(object->children); cobject;
			cobject = (elfGuiObject*)elfGetListNext(object->children))
		{
			elfSetGuiObjectRoot(cobject, root);
		}
	}

	object->root = root;
}

ELF_API elfGui* ELF_APIENTRY elfCreateGui()
{
	elfGui* gui;

	gui = (elfGui*)malloc(sizeof(elfGui));
	memset(gui, 0x0, sizeof(elfGui));
	gui->objType = ELF_GUI;
	gui->objDestr = elfDestroyGui;

	gui->visible = ELF_TRUE;

	gui->children = elfCreateList();
	gui->screens = elfCreateList();

	elfIncRef((elfObject*)gui->children);
	elfIncRef((elfObject*)gui->screens);

	gui->root = gui;

	gui->pos.x = gui->pos.y = 0;
	gui->updateSize = ELF_TRUE;
	gui->width = elfGetWindowWidth();
	gui->height = elfGetWindowHeight();

	elfIncObj(ELF_GUI);

	return gui;
}

void elfDestroyGui(void* data)
{
	elfGuiObject* object;
	elfGui* gui = (elfGui*)data;

	if(gui->name) elfDestroyString(gui->name);

	for(object = (elfGuiObject*)elfBeginList(gui->children); object;
		object = (elfGuiObject*)elfGetListNext(gui->children))
	{
		elfClearGuiObjectRoot(object);
		object->parent = NULL;
	}

	elfDecRef((elfObject*)gui->children);
	elfDecRef((elfObject*)gui->screens);

	free(gui);

	elfDecObj(ELF_GUI);
}

elfGuiObject* elfTraceTopObject(elfGuiObject* object, unsigned char click)
{
	elfGuiObject* cobject;
	elfGuiObject* result;
	elfVec2i mousePos;

	if(!object->visible) return ELF_FALSE;

	mousePos = elfGetMousePosition();
	mousePos.y = elfGetWindowHeight()-mousePos.y;

	if(object->objType == ELF_GUI && ((elfGui*)object)->focusScreen)
	{
		return elfTraceTopObject((elfGuiObject*)((elfGui*)object)->focusScreen, click);
	}

	result = NULL;
	if(object->screens)
	{
		for(cobject = (elfGuiObject*)elfRBeginList(object->screens); cobject;
			cobject = (elfGuiObject*)elfGetListRNext(object->screens))
		{
			if(mousePos.x >= cobject->pos.x && mousePos.x <= cobject->pos.x+cobject->width &&
				mousePos.y >= cobject->pos.y && mousePos.y <= cobject->pos.y+cobject->height &&
				cobject->visible)
			{
				if(click)
				{
					elfIncRef((elfObject*)cobject);
					elfRemoveListObject(object->screens, (elfObject*)cobject);
					elfAppendListObject(object->screens, (elfObject*)cobject);
					elfDecRef((elfObject*)cobject);
				}
				result = elfTraceTopObject(cobject, click);
				if(result) return result;
				return cobject;
			}
		}
	}

	result = NULL;
	if(object->children)
	{
		for(cobject = (elfGuiObject*)elfRBeginList(object->children); cobject;
			cobject = (elfGuiObject*)elfGetListRNext(object->children))
		{
			if(mousePos.x >= cobject->pos.x && mousePos.x <= cobject->pos.x+cobject->width &&
				mousePos.y >= cobject->pos.y && mousePos.y <= cobject->pos.y+cobject->height &&
				cobject->visible)
			{
				result = elfTraceTopObject(cobject, click);
				if(result) return result;
				return cobject;
			}
		}
	}

	if(mousePos.x >= object->pos.x && mousePos.x <= object->pos.x+object->width &&
		mousePos.y >= object->pos.y && mousePos.y <= object->pos.y+object->height)
	{
		return object;
	}

	return NULL;
}

void elfSendGuiCharEvent(elfGui* gui, char chr)
{
	char* str;

	if(chr < 32 || chr > 126) return;

	if(gui->activeTextField)
	{
		str = elfInsertCharToString(gui->activeTextField->text,
			gui->activeTextField->cursorPos, chr);
		elfDestroyString(gui->activeTextField->text);
		gui->activeTextField->text = str;
		elfMoveTextFieldCursorRight(gui->activeTextField);

		gui->activeTextField->event = ELF_CHAR_INPUT;
		if(gui->activeTextField->script)
		{
			eng->actor = (elfObject*)gui->activeTextField;
			elfIncRef((elfObject*)gui->activeTextField);

			elfRunString("me = GetActor(); event = CHAR_INPUT");
			elfRunScript(gui->activeTextField->script);
			elfRunString("me = nil; event = 0");

			elfDecRef((elfObject*)gui->activeTextField);
			eng->actor = NULL;
		}
	}
}

void elfSendGuiKeyEvent(elfGui* gui, int key)
{
	char* str;

	if(gui->activeTextField)
	{
		if(key == ELF_KEY_LEFT)
		{
			elfMoveTextFieldCursorLeft(gui->activeTextField);
		}
		else if(key == ELF_KEY_RIGHT)
		{
			elfMoveTextFieldCursorRight(gui->activeTextField);
		}
		else if(key == ELF_KEY_DEL)
		{
			if(gui->activeTextField->cursorPos < (int)strlen(gui->activeTextField->text))
			{
				str = elfRemoveCharFromString(gui->activeTextField->text,
					gui->activeTextField->cursorPos);
				elfDestroyString(gui->activeTextField->text);
				gui->activeTextField->text = str;
			}
		}
		else if(key == ELF_KEY_BACKSPACE)
		{
			if(gui->activeTextField->cursorPos > 0 &&
				strlen(gui->activeTextField->text) > 0)
			{
				str = elfRemoveCharFromString(gui->activeTextField->text,
					gui->activeTextField->cursorPos-1);
				elfDestroyString(gui->activeTextField->text);
				gui->activeTextField->text = str;
				elfMoveTextFieldCursorLeft(gui->activeTextField);
			}
		}
		else if(key == ELF_KEY_ENTER)
		{
			gui->activeTextField->event = ELF_LOSE_FOCUS;
			if(gui->activeTextField->script)
			{
				eng->actor = (elfObject*)gui->activeTextField;
				elfIncRef((elfObject*)gui->activeTextField);

				elfRunString("me = GetActor(); event = LOSE_FOCUS");
				elfRunScript(gui->activeTextField->script);
				elfRunString("me = nil; event = 0");

				elfDecRef((elfObject*)gui->activeTextField);
				eng->actor = NULL;
			}

			gui->activeTextField = NULL;
		}
	}
}

void elfResetGuiObjectEvents(elfGuiObject* object)
{
	elfGuiObject* obj;

	object->event = 0;

	if(object->children)
	{
		for(obj = (elfGuiObject*)elfBeginList(object->children); obj;
			obj = (elfGuiObject*)elfGetListNext(object->children))
		{
			elfResetGuiObjectEvents(obj);
		}
	}

	if(object->screens)
	{
		for(obj = (elfGuiObject*)elfBeginList(object->screens); obj;
			obj = (elfGuiObject*)elfGetListNext(object->screens))
		{
			elfResetGuiObjectEvents(obj);
		}
	}
}

void elfUpdateGui(elfGui* gui, float step)
{
	elfVec2i mouseForce;
	elfVec2i mousePosition;
	unsigned moved;
	elfGuiObject* prevTrace;
	elfObject* event;
	elfSlider* slider;
	elfTextList* textList;
	int i;

	if(gui->updateSize)
	{
		gui->width = elfGetWindowWidth();
		gui->height = elfGetWindowHeight();
		elfRecalcGuiObject((elfGuiObject*)gui);
	}

	elfResetGuiObjectEvents((elfGuiObject*)gui);

	mouseForce = elfGetMouseForce();
	mousePosition = elfGetMousePosition();

	moved = ELF_FALSE;
	if(mouseForce.x || mouseForce.y) moved = ELF_TRUE;

	prevTrace = gui->trace;
	gui->trace = elfTraceTopObject((elfGuiObject*)gui, elfGetMouseButtonState(ELF_BUTTON_LEFT) == ELF_PRESSED);

	if(gui->trace)
	{
		if(gui->trace->objType == ELF_BUTTON)
		{
			if(!gui->target)
			{
				((elfButton*)gui->trace)->state = ELF_OVER;
			}
			else if(gui->target == gui->trace)
			{
				((elfButton*)gui->trace)->state = ELF_ON;
			}
		}
	}

	if(prevTrace && prevTrace != gui->trace)
	{
		if(prevTrace->objType == ELF_BUTTON)
		{
			((elfButton*)prevTrace)->state = ELF_OFF;
		}
	}

	if(elfGetMouseButtonState(ELF_BUTTON_LEFT) == ELF_PRESSED)
	{
		if(gui->activeTextField && gui->activeTextField != (elfTextField*)gui->trace)
		{
			gui->activeTextField->event = ELF_LOSE_FOCUS;
			if(gui->activeTextField->script)
			{
				eng->actor = (elfObject*)gui->activeTextField;
				elfIncRef((elfObject*)gui->activeTextField);

				elfRunString("me = GetActor(); event = LOSE_FOCUS");
				elfRunScript(gui->activeTextField->script);
				elfRunString("me = nil; event = 0");

				elfDecRef((elfObject*)gui->activeTextField);
				eng->actor = NULL;
			}

			gui->activeTextField = NULL;
		}

		gui->target = gui->trace;

		if(gui->target)
		{
			if(gui->target->objType == ELF_BUTTON)
			{
				((elfButton*)gui->target)->state = ELF_ON;
			}
			else if(gui->target->objType == ELF_TEXT_FIELD)
			{
				gui->activeTextField = (elfTextField*)gui->target;

				gui->activeTextField->event = ELF_GAIN_FOCUS;
				if(gui->activeTextField->script)
				{
					eng->actor = (elfObject*)gui->activeTextField;
					elfIncRef((elfObject*)gui->activeTextField);

					elfRunString("me = GetActor(); event = GAIN_FOCUS");
					elfRunScript(gui->activeTextField->script);
					elfRunString("me = nil; event = 0");

					elfDecRef((elfObject*)gui->activeTextField);
					eng->actor = NULL;
				}
			}
			else if(gui->target->objType == ELF_SLIDER)
			{
				slider = (elfSlider*)gui->target;
				if(slider->width > slider->height)
				{
					slider->value = (float)(mousePosition.x-slider->pos.x)/((float)slider->width);
					if(slider->value < 0.0f) slider->value = 0.0f;
					if(slider->value > 1.0f) slider->value = 1.0f;
				}
				else
				{
					slider->value = (float)((elfGetWindowHeight()-mousePosition.y)-slider->pos.y)/((float)slider->height);
					if(slider->value < 0.0f) slider->value = 0.0f;
					if(slider->value > 1.0f) slider->value = 1.0f;
				}

				slider->event = ELF_VALUE_CHANGED;
				if(slider->script)
				{
					eng->actor = (elfObject*)gui->target;
					elfIncRef((elfObject*)gui->target);

					elfRunString("me = GetActor(); event = VALUE_CHANGED");
					elfRunScript(slider->script);
					elfRunString("me = nil; event = 0");

					elfDecRef((elfObject*)gui->target);
					eng->actor = NULL;
				}
			}
			else if(gui->target->objType == ELF_TEXT_LIST)
			{
				textList = (elfTextList*)gui->target;
				if(textList->font && elfGetListLength(textList->items) > 0)
				{
					textList->selection = textList->rows-1
						-(elfGetWindowHeight()-mousePosition.y-textList->pos.y)/
							(textList->font->size+textList->font->offsetY)
						+textList->offset;
					if(textList->selection > elfGetListLength(textList->items)-1) textList->selection = -1;

					textList->event = ELF_SELECTION_CHANGED;
					if(textList->script)
					{
						eng->actor = (elfObject*)gui->target;
						elfIncRef((elfObject*)gui->target);

						elfRunString("me = GetActor(); event = SELECTION_CHANGED");
						elfRunScript(textList->script);
						elfRunString("me = nil; event = 0");

						elfDecRef((elfObject*)gui->target);
						eng->actor = NULL;
					}
				}
			}
			else if(gui->target->objType == ELF_CHECK_BOX)
			{
				((elfCheckBox*)gui->target)->state = !((elfCheckBox*)gui->target)->state;

				((elfCheckBox*)gui->target)->event = ELF_STATE_CHANGED;
				if(((elfCheckBox*)gui->target)->script)
				{
					eng->actor = (elfObject*)gui->target;
					elfIncRef((elfObject*)gui->target);

					elfRunString("me = GetActor(); event = STATE_CHANGED");
					elfRunScript(((elfCheckBox*)gui->target)->script);
					elfRunString("me = nil; event = 0");

					elfDecRef((elfObject*)gui->target);
					eng->actor = NULL;
				}
			}
		}
	}
	else if(elfGetMouseButtonState(ELF_BUTTON_LEFT) == ELF_RELEASED)
	{
		if(gui->target)
		{
			if(gui->target->objType == ELF_BUTTON)
			{
				if(gui->target == gui->trace)
				{
					((elfButton*)gui->target)->event = ELF_CLICKED;
					if(((elfButton*)gui->target)->script)
					{
						eng->actor = (elfObject*)gui->target;
						elfIncRef((elfObject*)gui->target);

						((elfButton*)gui->target)->state = ELF_OFF;

						elfRunString("me = GetActor(); event = CLICKED");
						elfRunScript(((elfButton*)gui->target)->script);
						elfRunString("me = nil; event = 0");

						elfDecRef((elfObject*)gui->target);
						eng->actor = NULL;
					}
				}
			}
		}
		gui->target = NULL;
	}
	else if(elfGetMouseButtonState(ELF_BUTTON_LEFT) == ELF_DOWN && moved)
	{
		if(gui->target)
		{
			if(gui->target->objType == ELF_SLIDER)
			{
				slider = (elfSlider*)gui->target;
				if(slider->width > slider->height)
				{
					slider->value = (float)(mousePosition.x-slider->pos.x)/((float)slider->width);
					if(slider->value < 0.0f) slider->value = 0.0f;
					if(slider->value > 1.0f) slider->value = 1.0f;
				}
				else
				{
					slider->value = (float)((elfGetWindowHeight()-mousePosition.y)-slider->pos.y)/((float)slider->height);
					if(slider->value < 0.0f) slider->value = 0.0f;
					if(slider->value > 1.0f) slider->value = 1.0f;
				}

				slider->event = ELF_VALUE_CHANGED;
				if(slider->script)
				{
					eng->actor = (elfObject*)gui->target;
					elfIncRef((elfObject*)gui->target);

					elfRunString("me = GetActor(); event = VALUE_CHANGED");
					elfRunScript(slider->script);
					elfRunString("me = nil; event = 0");

					elfDecRef((elfObject*)gui->target);
					eng->actor = NULL;
				}
			}
		}
	}

#ifndef ELF_MACOSX
	if(gui->curKey)
	{
		gui->keyStep += step;

		if(gui->keyRepeat)
		{
			if(gui->keyStep >= 0.05f)
			{
				elfSendGuiKeyEvent(gui, gui->curKey);
				gui->keyStep = gui->keyStep-0.05f;
			}
		}
		else
		{
			if(gui->keyStep >= 0.35f)
			{
				elfSendGuiKeyEvent(gui, gui->curKey);
				gui->keyStep = gui->keyStep-0.35f;
				gui->keyRepeat = ELF_TRUE;
			}
		}
	}

	if(gui->curChar)
	{
		gui->charStep += step;

		if(gui->charRepeat)
		{
			if(gui->charStep >= 0.05f)
			{
				elfSendGuiCharEvent(gui, gui->curChar);
				gui->charStep = gui->charStep-0.05f;
			}
		}
		else
		{
			if(gui->charStep >= 0.35f)
			{
				elfSendGuiCharEvent(gui, gui->curChar);
				gui->charStep = gui->charStep-0.35f;
				gui->charRepeat = ELF_TRUE;
			}
		}
	}
#endif

	for(i = 0; i < elfGetEventCount(); i++)
	{
		event = elfGetEvent(i);

		if(event->objType == ELF_CHAR_EVENT)
		{
			if(((elfCharEvent*)event)->state == ELF_TRUE)
			{
				elfSendGuiCharEvent(gui, (char)((elfCharEvent*)event)->code);

				gui->curChar = (char)((elfCharEvent*)event)->code;
				gui->charStep = 0.0f;
			}
			else
			{
				gui->curChar = 0;
				gui->charStep = 0.0f;
				gui->charRepeat = ELF_FALSE;
			}
		}

		if(event->objType == ELF_KEY_EVENT)
		{
			if(((elfKeyEvent*)event)->state == ELF_TRUE)
			{
				elfSendGuiKeyEvent(gui, ((elfKeyEvent*)event)->key);

				gui->curKey = ((elfKeyEvent*)event)->key;
				gui->keyStep = 0.0f;
			}
			else
			{
				gui->curKey = 0;
				gui->keyStep = 0.0f;
				gui->keyRepeat = ELF_FALSE;
			}
		}
	}
}

void elfDrawGui(elfGui* gui)
{
	elfGuiObject* object;
	elfArea area;

	if(!gui->visible) return;

	area.pos.x = gui->pos.x;
	area.pos.y = gui->pos.y;
	area.size.x = gui->width;
	area.size.y = gui->height;

	gfxSetShaderParamsDefault(&gui->shaderParams);
	gui->shaderParams.renderParams.multisample = GFX_FALSE;
	gui->shaderParams.renderParams.depthWrite = GFX_FALSE;
	gui->shaderParams.renderParams.depthTest = GFX_FALSE;
	gui->shaderParams.renderParams.blendMode = GFX_TRANSPARENT;
	gfxSetViewport(gui->pos.x, gui->pos.y, gui->width, gui->height);
	gfxGetOrthographicProjectionMatrix((float)gui->pos.x, (float)gui->width, (float)gui->pos.x, (float)gui->height,
		-1.0f, 1.0f, gui->shaderParams.projectionMatrix);

	for(object = (elfGuiObject*)elfBeginList(gui->children); object;
		object = (elfGuiObject*)elfGetListNext(gui->children))
	{
		if(object->objType == ELF_LABEL) elfDrawLabel((elfLabel*)object, &gui->shaderParams);
		else if(object->objType == ELF_BUTTON) elfDrawButton((elfButton*)object, &gui->shaderParams);
		else if(object->objType == ELF_PICTURE) elfDrawPicture((elfPicture*)object, &gui->shaderParams);
		else if(object->objType == ELF_TEXT_FIELD)
		{
			elfDrawTextField((elfTextField*)object, &area, &gui->shaderParams);
			gfxSetViewport(gui->pos.x, gui->pos.y, gui->width, gui->height);
			gfxGetOrthographicProjectionMatrix((float)gui->pos.x, (float)gui->pos.x+gui->width, (float)gui->pos.y, (float)gui->pos.y+gui->height,
				-1.0f, 1.0f, gui->shaderParams.projectionMatrix);
		}
		else if(object->objType == ELF_TEXT_LIST)
		{
			elfDrawTextList((elfTextList*)object, &area, &gui->shaderParams);
			gfxSetViewport(gui->pos.x, gui->pos.y, gui->width, gui->height);
			gfxGetOrthographicProjectionMatrix((float)gui->pos.x, (float)gui->pos.x+gui->width, (float)gui->pos.y, (float)gui->pos.y+gui->height,
				-1.0f, 1.0f, gui->shaderParams.projectionMatrix);
		}
		else if(object->objType == ELF_SLIDER) elfDrawSlider((elfSlider*)object, &gui->shaderParams);
		else if(object->objType == ELF_CHECK_BOX) elfDrawCheckBox((elfCheckBox*)object, &gui->shaderParams);
	}

	for(object = (elfGuiObject*)elfBeginList(gui->screens); object;
		object = (elfGuiObject*)elfGetListNext(gui->screens))
	{
		area.pos.x = gui->pos.x; area.pos.y = gui->pos.y; area.size.x = gui->width; area.size.y = gui->height;
		elfDrawScreen((elfScreen*)object, &area, &gui->shaderParams);
		gfxSetViewport(gui->pos.x, gui->pos.y, gui->width, gui->height);
		gfxGetOrthographicProjectionMatrix((float)gui->pos.x, (float)gui->pos.x+gui->width, (float)gui->pos.y, (float)gui->pos.y+gui->height,
			-1.0f, 1.0f, gui->shaderParams.projectionMatrix);
	}

	// reset state just to be sure...
	gfxSetShaderParamsDefault(&gui->shaderParams);
	gfxSetShaderParams(&gui->shaderParams);
}

ELF_API unsigned char ELF_APIENTRY elfAddGuiObject(elfGuiObject* parent, elfGuiObject* object)
{
	if(parent->objType != ELF_GUI && parent->objType != ELF_SCREEN) return ELF_FALSE;
	if(object->parent) elfRemoveGuiObjectByObject(object->parent, object);
	elfSetGuiObjectRoot(object, parent->root);
	object->parent = parent;
	elfRecalcGuiObject(object);
	if(object->objType != ELF_SCREEN) elfAppendListObject(parent->children, (elfObject*)object);
	else elfAppendListObject(parent->screens, (elfObject*)object);
	return ELF_TRUE;
}

ELF_API elfGuiObject* ELF_APIENTRY elfGetGuiObjectByName(elfGuiObject* parent, const char* name)
{
	elfGuiObject* object;

	if(!strcmp(parent->name, name)) return parent;

	if(parent->children)
	{
		for(object = (elfGuiObject*)elfBeginList(parent->children); object;
			object = (elfGuiObject*)elfGetListNext(parent->children))
		{
			elfGetGuiObjectByName(object, name);
		}
	}

	if(parent->screens)
	{
		for(object = (elfGuiObject*)elfBeginList(parent->screens); object;
			object = (elfGuiObject*)elfGetListNext(parent->screens))
		{
			elfGetGuiObjectByName(object, name);
		}
	}

	return NULL;
}

ELF_API elfGuiObject* ELF_APIENTRY elfGetGuiObjectByIndex(elfGuiObject* parent, int idx)
{
	elfGuiObject* object;
	int i;

	if(parent->objType != ELF_GUI && parent->objType == ELF_SCREEN) return ELF_FALSE;

	if(idx < 0 || idx > elfGetListLength(parent->children)+elfGetListLength(parent->screens)-1) return ELF_FALSE;

	if(idx < elfGetListLength(parent->children))
	{
		for(i = 0, object = (elfGuiObject*)elfBeginList(parent->children); object;
			i++, object = (elfGuiObject*)elfGetListNext(parent->children))
		{
			if(i == idx) return object;
		}
	}
	else
	{
		idx -= elfGetListLength(parent->children);
		for(i = 0, object = (elfGuiObject*)elfBeginList(parent->screens); object;
			i++, object = (elfGuiObject*)elfGetListNext(parent->screens))
		{
			if(i == idx) return object;
		}
	}

	return ELF_FALSE;
}

ELF_API unsigned char ELF_APIENTRY elfRemoveGuiObjectByName(elfGuiObject* parent, const char* name)
{
	elfGuiObject* object;

	if(parent->objType != ELF_GUI && parent->objType != ELF_SCREEN) return ELF_FALSE;

	for(object = (elfGuiObject*)elfBeginList(parent->children); object;
		object = (elfGuiObject*)elfGetListNext(parent->children))
	{
		if(!strcmp(object->name, name))
		{
			if(object->root)
			{
				if(object->root->trace == object) object->root->trace = NULL;
				if(object->root->target == object) object->root->target = NULL;
				if(object->root->activeTextField == (elfTextField*)object)
					object->root->activeTextField = NULL;
			}
			object->parent = NULL;
			elfClearGuiObjectRoot(object);
			elfRemoveListObject(parent->children, (elfObject*)object);
			return ELF_TRUE;
		}
	}

	for(object = (elfGuiObject*)elfBeginList(parent->screens); object;
		object = (elfGuiObject*)elfGetListNext(parent->screens))
	{
		if(!strcmp(object->name, name))
		{
			if(object->root)
			{
				if(object->root->trace == object) object->root->trace = NULL;
				if(object->root->target == object) object->root->target = NULL;
				if(object->root->focusScreen == (elfScreen*)object)
					object->root->focusScreen = NULL;
			}
			object->parent = NULL;
			elfClearGuiObjectRoot(object);
			elfRemoveListObject(parent->children, (elfObject*)object);
			return ELF_TRUE;
		}
	}

	return ELF_FALSE;
}

ELF_API unsigned char ELF_APIENTRY elfRemoveGuiObjectByIndex(elfGuiObject* parent, int idx)
{
	elfGuiObject* object;
	int i;

	if(parent->objType != ELF_GUI && parent->objType == ELF_SCREEN) return ELF_FALSE;

	if(idx < 0 || idx > elfGetListLength(parent->children)+elfGetListLength(parent->screens)-1) return ELF_FALSE;

	if(idx < elfGetListLength(parent->children))
	{
		for(i = 0, object = (elfGuiObject*)elfBeginList(parent->children); object;
			i++, object = (elfGuiObject*)elfGetListNext(parent->children))
		{
			if(i == idx)
			{
				if(object->root)
				{
					if(object->root->trace == object) object->root->trace = NULL;
					if(object->root->target == object) object->root->target = NULL;
					if(object->root->activeTextField == (elfTextField*)object)
						object->root->activeTextField = NULL;
				}
				object->parent = NULL;
				elfClearGuiObjectRoot(object);
				elfRemoveListObject(parent->children, (elfObject*)object);
				return ELF_TRUE;
			}
		}
	}
	else
	{
		idx -= elfGetListLength(parent->children);
		for(i = 0, object = (elfGuiObject*)elfBeginList(parent->screens); object;
			i++, object = (elfGuiObject*)elfGetListNext(parent->screens))
		{
			if(i == idx)
			{
				if(object->root)
				{
					if(object->root->trace == object) object->root->trace = NULL;
					if(object->root->target == object) object->root->target = NULL;
					if(object->root->focusScreen == (elfScreen*)object)
						object->root->focusScreen = NULL;
				}
				object->parent = NULL;
				elfClearGuiObjectRoot(object);
				elfRemoveListObject(parent->children, (elfObject*)object);
				return ELF_TRUE;
			}
		}
	}

	return ELF_FALSE;
}

ELF_API unsigned char ELF_APIENTRY elfRemoveGuiObjectByObject(elfGuiObject* parent, elfGuiObject* object)
{
	if(parent->objType != ELF_GUI && parent->objType != ELF_SCREEN) return ELF_FALSE;
	
	if(object->root)
	{
		if(object->root->trace == object) object->root->trace = NULL;
		if(object->root->target == object) object->root->target = NULL;
		if(object->root->activeTextField == (elfTextField*)object)
			object->root->activeTextField = NULL;
		if(object->root->focusScreen == (elfScreen*)object)
			object->root->focusScreen = NULL;
	}
	object->parent = NULL;
	elfClearGuiObjectRoot(object);
	if(object->objType != ELF_SCREEN) return elfRemoveListObject(parent->children, (elfObject*)object);
	else return elfRemoveListObject(parent->screens, (elfObject*)object);
}

ELF_API elfGuiObject* ELF_APIENTRY elfGetGuiTrace(elfGui* gui)
{
	if(!gui->trace || gui->trace->objType == ELF_GUI) return NULL;
	return gui->trace;
}

ELF_API elfGuiObject* ELF_APIENTRY elfGetGuiFocus(elfGui* gui)
{
	return (elfGuiObject*)gui->focusScreen;
}

ELF_API elfGuiObject* ELF_APIENTRY elfGetGuiActiveTextField(elfGui* gui)
{
	return (elfGuiObject*)gui->activeTextField;
}

ELF_API void ELF_APIENTRY elfEmptyGui(elfGui* gui)
{
	elfDecRef((elfObject*)gui->children);
	elfDecRef((elfObject*)gui->screens);
	gui->children = elfCreateList();
	gui->screens = elfCreateList();
	elfIncRef((elfObject*)gui->children);
	elfIncRef((elfObject*)gui->screens);
}

