
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
        
        float Ambient[] = {0.2, 0.2, 0.2, 1.0};
        float Diffuse[] = {0.8, 0.8, 0.8, 1.0};
        float Specular[] = {0.0, 0.0, 0.0, 1.0};
        float Emission[] = {0.0, 0.0, 0.0, 1.0};
        float Shininess = 0.0;
        
        if(m_Ambient == NULL) m_Ambient = (float*)Ambient;
        if(m_Diffuse == NULL) m_Diffuse = (float*)Diffuse;
        if(m_Specular == NULL) m_Specular = (float*)Specular;
        if(m_Emission == NULL) m_Emission = (float*)Emission;
        if(m_Shininess == NULL) m_Shininess = Shininess;
        
        
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

