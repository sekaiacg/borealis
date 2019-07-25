/*
    Borealis, a Nintendo Switch UI Library
    Copyright (C) 2019  WerWolv

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <View.hpp>
#include <FrameContext.hpp>

enum class ImageScaleType {
    NO_RESIZE = 0,
    FIT,
    CROP,
    SCALE,
    VIEW_RESIZE
};

// An image
class Image : public View
{
    protected:
        void layout(NVGcontext* vg, Style *style, FontStash *stash) override;

    public:
        Image(string imagePath);
        Image(unsigned char *buffer, size_t bufferSize);
        ~Image();

        void draw(NVGcontext *vg, int x, int y, unsigned width, unsigned height, Style *style, FrameContext *ctx) override;

        void setImage(unsigned char *buffer, size_t bufferSize);
        void setImage(string imagePath);

        void setOpacity(float opacity);
        void setImageScaleType(ImageScaleType imageScaleType);

    private:
        string imagePath;
        unsigned char *imageBuffer = nullptr;
        size_t imageBufferSize = 0;

        int texture = -1;
        NVGpaint imgPaint;

        ImageScaleType imageScaleType = ImageScaleType::NO_RESIZE;

        int imageX = 0, imageY = 0;
        int imageWidth = 0, imageHeight = 0;
        float opacity = 1.0F;
};