uniform sampler2D diffuse;
uniform vec2 lightPosition;

varying vec2 texCoordVar;
varying vec2 varPosition;

float attenuate(float dist, float a, float b)
{
     // Adjust these parameters for better light falloff
     return 1.0 / (1.0 + (a * dist) + (b * dist * dist));
}

void main()
{
    // Calculate distance between fragment position and light position
    float dist = distance(lightPosition, varPosition);
    
    // Calculate brightness with adjusted attenuation parameters
    // Lower 'a' value makes the light reach further
    float brightness = attenuate(dist, 0.3, 0.01);
    
    // Add some ambient light so areas aren't completely dark
    brightness = max(brightness, 0.15);
    
    // Apply the lighting to the texture color
    vec4 color = texture2D(diffuse, texCoordVar);
    gl_FragColor = vec4(color.rgb * brightness, color.a);
}