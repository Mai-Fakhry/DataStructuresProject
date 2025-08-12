#include "Forum.hpp"

Forum::Forum() : lastPostId(0) {}

void Forum::addPost(const string& content, const string& author, int parentId, const string& quotedContent) {
    lastPostId++;
    Post newPost(lastPostId, content, author, parentId, quotedContent);
    posts[lastPostId] = newPost;//Add the post to the posts map and the key is the id

    if (parentId != 0) {
        posts[parentId].addReply(newPost);
    }
}

int Forum::getLastPostId() const {
    return lastPostId;
}
//Display post with its replies
void Forum::displayPostChain(int postId) {
    stack<Post> postChain;
    int currentId = postId;

    while (currentId != 0) {
        postChain.push(posts.at(currentId));
        currentId = posts.at(currentId).getParentId();
    }

    while (!postChain.empty()) {
        cout << postChain.top();
        postChain.pop();
    }
}

Post Forum::getPostById(int postId) {
    return posts.at(postId);
}
//Display all forum
void Forum::displayForum() const {
    for (const auto& postEntry : posts) {
        postEntry.second.display(cout);
    }
}
