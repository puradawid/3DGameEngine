
#ifndef MATERIAL_H
#define	MATERIAL_H

#ifdef	__cplusplus
extern "C" {
#endif

class Material
{
public:
    Material(float* ambient, float* diffuse, float* specular,
            float* emission, float shininess)
    {
        m_Ambient = ambient;
        m_Specular = specular;
        m_Diffuse = diffuse;
        m_Specular = specular;
        m_Emission = emission;
        m_Shininess = shininess;
        
        float Ambient[] = {0.1, 0.1, 0.1, 1.0};
        float Diffuse[] = {0.5, 0.5, 0.5, 1};
        float Specular[] = {0.4, 0.4, 0.4, 1.0};
        float Emission[] = {0.1, 0.1, 0.1, 1.0};
        float Shininess = 0.9;
        
        m_Ambient = copyArray((float*)Ambient, 4);
        m_Diffuse = copyArray((float*)Diffuse, 4);
        m_Specular = copyArray((float*)Specular, 4);
        m_Emission = copyArray((float*)Emission, 4);
        m_Shininess = Shininess;
        
        
    }
    
    float* copyArray(float* src, int size)
    {
        float *dst = new float[size];
        for(int i = 0; i < size; i++)
            dst[i] = src[i];
        return dst;
    }
    
    void Apply()
    {
        glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, m_Ambient );
        glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, m_Diffuse);
        glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, m_Specular );
        glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, m_Emission );
        glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, m_Shininess );
    }
protected:
    float* m_Ambient;
    float* m_Diffuse;
    float* m_Specular;
    float* m_Emission;
    float  m_Shininess;
 
};


#ifdef	__cplusplus
}
#endif

#endif	/* MATERIAL_H */

