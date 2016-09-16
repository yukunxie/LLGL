/*
 * RenderContextFlags.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_RENDER_CONTEXT_FLAGS_H__
#define __LLGL_RENDER_CONTEXT_FLAGS_H__


namespace LLGL
{


/* ----- Enumerations ----- */

//! \brief Primitive topology enumeration.
enum class PrimitiveTopology
{
    PointList,              //!< Point list.

    LineList,               //!< Line list where each line has its own two vertices.
    LineStrip,              //!< Line strip where each line after the first one begins with the previous vertex.

    /**
    \brief Line loop which is similiar to line strip but the last line ends with the first vertex.
    \note This is only supported with OpenGL.
    */
    LineLoop,

    LineListAdjacency,      //!< Adjacency line list.
    LineStripAdjacency,     //!< Adjacency line strips.

    TriangleList,           //!< Triangle list where each triangle has its own three vertices.
    TriangleStrip,          //!< Triangle strip where each triangle after the first one begins with the previous vertex.

    /**
    \brief Triangle fan where each triangle uses the first vertex, the previous vertex, and a new vertex.
    \note This is only supported with OpenGL.
    */
    TriangleFan,

    TriangleListAdjacency,  //!< Adjacency triangle list.
    TriangleStripAdjacency, //!< Adjacency triangle strips.

    Patches1,               //!< Patches with 1 control point.
    Patches2,               //!< Patches with 2 control points.
    Patches3,               //!< Patches with 3 control points.
    Patches4,               //!< Patches with 4 control points.
    Patches5,               //!< Patches with 5 control points.
    Patches6,               //!< Patches with 6 control points.
    Patches7,               //!< Patches with 7 control points.
    Patches8,               //!< Patches with 8 control points.
    Patches9,               //!< Patches with 9 control points.
    Patches10,              //!< Patches with 10 control points.
    Patches11,              //!< Patches with 11 control points.
    Patches12,              //!< Patches with 12 control points.
    Patches13,              //!< Patches with 13 control points.
    Patches14,              //!< Patches with 14 control points.
    Patches15,              //!< Patches with 15 control points.
    Patches16,              //!< Patches with 16 control points.
    Patches17,              //!< Patches with 17 control points.
    Patches18,              //!< Patches with 18 control points.
    Patches19,              //!< Patches with 19 control points.
    Patches20,              //!< Patches with 20 control points.
    Patches21,              //!< Patches with 21 control points.
    Patches22,              //!< Patches with 22 control points.
    Patches23,              //!< Patches with 23 control points.
    Patches24,              //!< Patches with 24 control points.
    Patches25,              //!< Patches with 25 control points.
    Patches26,              //!< Patches with 26 control points.
    Patches27,              //!< Patches with 27 control points.
    Patches28,              //!< Patches with 28 control points.
    Patches29,              //!< Patches with 29 control points.
    Patches30,              //!< Patches with 30 control points.
    Patches31,              //!< Patches with 31 control points.
    Patches32,              //!< Patches with 32 control points.
};

/**
\brief Enumeration of all renderer info entries.
\see RenderContext::QueryRendererInfo
*/
enum class RendererInfo
{
    Version,
    Vendor,
    Hardware,
    ShadingLanguageVersion,
};



/* ----- Structures ----- */

/**
\brief Render context clear buffer flags.
\see RenderContext::ClearBuffers
*/
struct ClearBuffersFlags
{
    enum
    {
        Color   = (1 << 0),
        Depth   = (1 << 1),
        Stencil = (1 << 2),
    };
};

/**
\brief Viewport dimensions.
\remarks A viewport is in screen coordinates where the origin is in the left-top corner.
*/
struct Viewport
{
    Viewport() = default;
    Viewport(const Viewport&) = default;
    
    Viewport(float x, float y, float width, float height) :
        x       ( x      ),
        y       ( y      ),
        width   ( width  ),
        height  ( height )
    {
    }
    
    Viewport(float x, float y, float width, float height, float minDepth, float maxDepth) :
        x       ( x        ),
        y       ( y        ),
        width   ( width    ),
        height  ( height   ),
        minDepth( minDepth ),
        maxDepth( maxDepth )
    {
    }

    float x         = 0.0f; //!< Left-top X coordinate.
    float y         = 0.0f; //!< Left-top Y coordinate.
    float width     = 0.0f; //!< Right-bottom width.
    float height    = 0.0f; //!< Right-bottom height.
    float minDepth  = 0.0f; //!< Minimal depth range.
    float maxDepth  = 1.0f; //!< Maximal depth range.
};

/**
\brief Scissor dimensions.
\remarks A scissor is in screen coordinates where the origin is in the left-top corner.
*/
struct Scissor
{
    Scissor() = default;
    Scissor(const Scissor&) = default;

    Scissor(int x, int y, int width, int height) :
        x       ( x      ),
        y       ( y      ),
        width   ( width  ),
        height  ( height )
    {
    }

    int x       = 0;
    int y       = 0;
    int width   = 0;
    int height  = 0;
};

/**
\brief Low-level graphics API dependent state descriptor union.
\see RenderContext::SetGraphicsAPIDependentState
*/
union GraphicsAPIDependentStateDescriptor
{
    GraphicsAPIDependentStateDescriptor()
    {
        stateOpenGL.flipViewportVertical = false;
    }

    struct StateOpenGLDescriptor
    {
        /**
        \briefs Specifies whether to flip the viewport setttings vertical. By default false.
        \remarks If this is true, the front facing will be inverted everytime "BindGraphicsPipeline" is called,
        and everytime the viewports and scissors are set, their origin will be lower-left instead of upper-left.
        This can be used for compatability with other renderers such as Direct3D when a render target is bound.
        \see RasterizerDescriptor::frontCCW
        \see RenderContext::BindGraphicsPipeline
        */
        bool flipViewportVertical;
    }
    stateOpenGL;
};


} // /namespace LLGL


#endif



// ================================================================================
