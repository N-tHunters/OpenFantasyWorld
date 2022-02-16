#include <assets/model.hpp>

Model::Model(const std::string& path) {
	this->LoadModel(path);
}

void Model::LoadModel(const std::string& path) {
	Assimp::Importer import;

	const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		printf("ERROR::ASSIMP::%s\n", import.GetErrorString());
		return;
	}

	this->ProcessNode(scene->mRootNode, scene);
}

void Model::ProcessNode(aiNode *node, const aiScene *scene)
{
	for (unsigned int m = 0; m < scene->mNumMeshes; ++m) {
		const aiMesh *mesh = scene->mMeshes[m];
		// iterate over all faces in this mesh
		for (unsigned int j = 0; j < mesh->mNumFaces; ++j) {
			auto const &face = mesh->mFaces[j];
			//normally you want just triangles, so iterate over all 3 vertices of the face:
			for (int k = 0; k < face.mNumIndices; ++k) {
				// Now do the magic with 'face.mIndices[k]'
				auto const &vertex = mesh->mVertices[face.mIndices[k]];
				vertices.push_back(vertex.x);
				vertices.push_back(vertex.y);
				vertices.push_back(vertex.z);

				// Same for the normals.
				auto const &normal = mesh->mNormals[face.mIndices[k]];
				vertices.push_back(normal.x);
				vertices.push_back(normal.y);
				vertices.push_back(normal.z);

				// And FINALLY: The UV coordinates!
				if (mesh->HasTextureCoords(0)) {
					// The following line fixed the issue for me now:
					auto const &uv = mesh->mTextureCoords[0][face.mIndices[k]];
					vertices.push_back(uv.x);
					vertices.push_back(uv.y);
				} else {
					vertices.push_back(0.0f);
					vertices.push_back(0.0f);
				}
				indices.push_back(face.mIndices[k]);
			}
		}
	}
}